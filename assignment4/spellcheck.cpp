// 1. 先包含项目自身的头文件
#include "spellcheck.h"

// 2. 再包含所有需要的 C++ 标准库头文件
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>   // <-- 为 std::inner_product 提供定义
#include <ranges>
#include <set>
#include <string>
#include <vector>

// 3. 最后再包含依赖上面这些头文件的 .cpp 文件
#include "utils.cpp"


Corpus tokenize(std::string& source) {
    // 第一步：找到所有指向空格字符（以及字符串头尾）的迭代器
    auto space_iterators = find_all(source.begin(), source.end(), ::isspace);

    Corpus tokens; // 创建一个空的 set 用来存放结果

    // 第二步：根据连续的迭代器对，生成令牌
    std::transform(
        space_iterators.begin(),
        space_iterators.end() - 1,
        space_iterators.begin() + 1,
        std::inserter(tokens, tokens.end()),
        // 这个 lambda 函数接收一对连续的迭代器，并用它们创建一个 Token
        [&source](auto it1, auto it2) {
            return Token(source, it1, it2);
        }
    );

    // 第三步：移除内容为空的令牌
    std::erase_if(tokens, [](const Token& t) {
        return t.content.empty();
    });

    // 返回最终的令牌集合
    return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    // 为方便起见，创建一个命名空间别名
    namespace rv = std::ranges::views;

    // 创建一个处理语料库的视图“流水线”
    auto misspelling_view = source
        // 第一步：筛选，只保留拼写错误的单词
        | rv::filter([&dictionary](const Token& token) {
            return !dictionary.contains(token.content);
        })

        // 第二步：将每个拼写错误的 token 转换为一个 Misspelling 结构体
        | rv::transform([&dictionary](const Token& token) {
            // 对于每个 token，创建一个字典的视图...
            auto suggestions_view = dictionary
                // ...并筛选它，以找到 Levenshtein 距离为 1 的单词
                | rv::filter([&token](const std::string& dict_word) {
                    return levenshtein(token.content, dict_word) == 1;
                });
            
            // 将建议词的视图“物化”成一个 std::set
            std::set<std::string> suggestions(suggestions_view.begin(), suggestions_view.end());

            // 返回最终的 Misspelling 对象
            return Misspelling{ token, suggestions };
        })

        // 第三步：筛选，丢弃那些没有任何建议的拼写错误
        | rv::filter([](const Misspelling& m) {
            return !m.suggestions.empty();
        });

    // 将最终的 Misspelling 对象视图“物化”成一个集合并返回
    return std::set<Misspelling>(misspelling_view.begin(), misspelling_view.end());
}
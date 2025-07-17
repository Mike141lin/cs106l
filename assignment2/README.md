# CS106L 核心知识点与实践总结 (结合项目经验)

这份文档总结了在完成 C++ 编程作业（如 `SimpleEnroll` 和 `Marriage Pact`）过程中，我们遇到的核心知识点和应用。它将理论与我们共同解决的实际问题相结合，以加深理解。

---

## 1. C++ 核心编程概念

### a. 文件输入/输出 (File I/O)
- **核心工具**: C++ 通过**流 (stream)** 的概念来处理 I/O，需要包含 `<fstream>` 头文件。
- **在本作业中的应用**:
    - **读取文件**: 在 `parse_csv` 函数中，我们使用 `std::ifstream file("courses.csv");` 来打开并读取课程数据。
    - **写入文件**: 在 `write_courses_offered` 和 `write_courses_not_offered` 函数中，我们使用 `std::ofstream outfile(...)` 来创建并写入新的 CSV 文件，包括表头和数据行。

### b. 字符串处理
- **核心工具**: `#include <string>` 提供了 `std::string` 类型；`#include <sstream>` 提供了**字符串流 (stringstream)**，是处理和分割字符串的利器。
- **在本作业中的应用**:
    - 在 `parse_csv` 中，我们利用课程提供的 `split` 函数（其内部就是用 `stringstream` 实现的）来高效地分割从文件中读取的每一行数据。
    - 在 `Marriage Pact` 作业中，我们自己编写了 `get_initials` 辅助函数，同样使用 `stringstream` 轻松地从一个全名中分离出姓和名，以提取首字母。

### c. 函数与参数传递
- **传值 (Pass-by-Value)** vs. **传引用 (Pass-by-Reference)** 是本次实践的核心概念之一。
- **在本作业中的应用**:
    - 我们最初遇到的一个关键问题就是 `parse_csv` 无法修改 `main` 函数中的 `courses` 向量。
    - **解决方案**: 我们将 `parse_csv`, `write_courses_offered` 等函数的参数从 `std::vector<Course> courses` 修改为 **`std::vector<Course>& courses`**。
    - **学习成果**: 通过加一个 `&` 符号，我们不再创建整个向量的低效副本，而是传递了一个直接指向原始向量的“引用”，使得函数内的所有修改都能影响到 `main` 函数，这对于修改和过滤数据至关重要。

### d. 指针 (`*`) 与内存管理
- **核心概念**: 指针存储的是内存地址，它“指向”另一个数据。
- **在本作业中的应用**:
    - 在 `Marriage Pact` 作业的 `find_matches` 函数中，我们被要求在队列中存储 **`const std::string*`**（指向字符串的指针）而不是字符串本身。
    - **学习成果**: 我们理解了这样做的**效率优势**（复制指针远快于复制长字符串），同时也探讨了其**风险**——如果原始的 `students` 集合被销毁，队列中的指针就会变成**悬垂指针 (Dangling Pointer)**，再使用它们会导致危险的**未定义行为**。

---

## 2. 关键数据结构 (STL)

### a. `std::vector` - 动态数组
- **在本作业中的应用**: 在 `SimpleEnroll` 作业中，`std::vector` 是我们的第一个主力容器。`parse_csv` 函数将所有从文件读取的 `Course` 对象都首先存放在一个 `std::vector` 中，为后续的处理做准备。

### b. `std::unordered_set` - 无序集合
- **底层结构**: 哈希表 (Hash Table)，提供 O(1) 的平均查找效率。
- **在本作业中的应用**:
    - 在 `Marriage Pact` 作业中，我们需要存储大量唯一的学生名单。我们分析了 `set` 和 `unordered_set` 的区别，并最终选择了 `std::unordered_set`，因为它不要求排序，且查找速度最快。
    * **实践教训**: 我们遇到的一个编译错误（`no matching function for call to 'find_matches'`）最终揭示了，自动评分器期望我们使用的正是 `std::unordered_set`，这印证了我们基于性能分析做出的选择是正确的。

### c. `std::queue` - 队列
- **核心特性**: 先进先出 (First-In, First-Out, FIFO)。
- **在本作业中的应用**: 在 `find_matches` 的结果存储中，我们使用了 `std::queue`。这让我们按照找到匹配者的先后顺序来处理他们，`push()` 进队，`pop()` 出队，`front()` 查看队首元素，完美契合了处理流程。

---

## 3. 开发与调试工作流

### a. 编译代码 (`g++`)
- **在本作业中的应用**: 我们遇到了一个非常微妙但关键的编译问题。
    * **问题**: 同时编译 `main.cpp` 和 `utils.cpp` (`g++ main.cpp utils.cpp`) 导致了大量错误。
    * **学习成果**: 通过分析，我们发现 `main.cpp` 中已经包含了 `#include "utils.cpp"`。这意味着 `utils.cpp` 的代码已经被“粘贴”进了 `main.cpp`。因此，**正确的编译命令只需要编译 `main.cpp` 即可** (`g++ main.cpp -o main`)。这个经验教会我们 `include` 一个 `.cpp` 文件（虽然不常见，但在此作业中是这样设计的）对编译命令的影响。

### b. 版本控制 (Git & GitHub)
- **在本作业中的应用**: 我们解决了一个非常真实的 Git 工作流问题。
    * **问题**: `git push` 时遇到 `rejected (fetch first)` 和 `divergent branches` 错误。
    * **学习成果**: 我们学会了这是因为云端仓库有了本地没有的更新。标准的解决方案是先 **`git pull`**。我们还学习了如何处理分支分岔，通过 `git pull --no-rebase` 和设置 `git config pull.rebase false` 来选择“合并”策略。
    * **认证**: 我们解决了 GitHub 不再支持密码认证的问题，学会了如何生成、配置并使用**个人访问令牌 (PAT)**，并理解了 `repo` 权限的重要性。

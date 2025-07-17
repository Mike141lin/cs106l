/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream> 

std::string kYourName = "LIU Jielin"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // 1. 创建一个文件输入流来打开文件
    std::ifstream file(filename);
    
    // 2. 创建一个空的无序集合，用来存储学生姓名
    std::unordered_set<std::string> applicants;
    
    std::string name; // 用来存储从文件中读取的每一行（即一个名字）

    // 3. 逐行读取文件
    // 当 getline 成功读取到一行时，循环继续
    while (std::getline(file, name)) {
        // 4. 将读取到的名字插入到集合中
        // 集合会自动处理重复的名字，不会重复添加
        applicants.insert(name);
    }
    
    // 5. 返回填充好的集合
    return applicants;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
 // 输入一个全名（如 "Fabio Ibanez"），返回其首字母缩写（如 "FI"）
std::string get_initials(const std::string& name) {
    std::stringstream ss(name);
    std::string first, last, initials;
    
    // stringstream 会自动按空格分割
    ss >> first >> last;

    if (!first.empty()) {
        initials += first[0];
    }
    if (!last.empty()) {
        initials += last[0];
    }
    
    return initials;
}
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // 1. 创建一个空的队列，用来存放指向匹配姓名的指针
std::queue<const std::string*> matches;

// 2. 获取目标姓名（参数 name）的首字母
std::string target_initials = get_initials(name);

// 3. 遍历 students 集合中的每一个名字
for (const std::string& student_name : students) {
    // 4. 获取当前学生姓名的首字母
    std::string student_initials = get_initials(student_name);
    
    // 5. 如果首字母匹配
    if (student_initials == target_initials) {
        // 将指向 set 中这个名字的指针（&student_name）添加到队列中
        matches.push(&student_name);
    }
}

// 6. 返回填充好的队列
return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // 1. 检查队列是否为空
if (matches.empty()) {
    // 如果没有匹配项，按要求返回指定字符串
    return "NO MATCHES FOUND.";
}

// 2. 一个比“直接取第一个”更复杂的选择策略
//    例如，我们跳过队列中一半的人，选择中间的那一个作为“真爱”
//    size_t 是一个表示大小的无符号整数类型
size_t num_to_skip = matches.size() / 2;
for (size_t i = 0; i < num_to_skip; ++i) {
    matches.pop(); // 从队列前面移除元素
}

// 3. 获取选择的“真爱”
const std::string* match_ptr = matches.front(); // 获取队首元素的指针

// 4. 返回名字本身（通过解引用指针 * 来获取字符串）
return *match_ptr;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"

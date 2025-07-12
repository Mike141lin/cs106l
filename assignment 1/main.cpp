/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 */
struct Course {
    std::string title;           // 课程标题是文本
    std::string number_of_units; // 学分是整数
    std::string quarter;         // 学期也是文本
};

/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * This function should populate the `courses` vector with structs of type
 * `Course`. We want to create these structs with the records in the courses.csv
 * file, where each line is a record!
 *
 * Hints:
 * 1) Take a look at the split function we provide in utils.cpp
 * 2) Each LINE is a record! *this is important, so we're saying it again :>)*
 * 3) The first line in the CSV defines the column names, so you can ignore it!
 *
 * @param filename The name of the file to parse.
 * @param courses  A vector of courses to populate.
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  // 错误修正：补上被删除的 打开文件 和 定义line变量 的代码
  std::ifstream file(filename);
  std::string line;

  // 错误修正：补上被删除的 忽略第一行（表头） 的代码
  if (file.is_open()) {
    std::getline(file, line);
  }

  // 逐行读取文件的其余部分
  while (std::getline(file, line)) {
    std::vector<std::string> parts = split(line, ',');
    
    if (parts.size() == 3) {
      Course current_course;
      current_course.title = parts[0];
      current_course.number_of_units = parts[1];
      current_course.quarter = parts[2];
      courses.push_back(current_course);
    }
  }
}


/**
 * This function has TWO requirements.
 *
 * 1) Write the courses that are offered to the file
 * "student_output/courses_offered.csv"
 *
 * 2) Delete the courses that are offered from the `all_courses` vector.
 * IMPORTANT: do this after you write out to the file!
 *
 * HINTS:
 * 1) Keep track of the classes that you need to delete!
 * 2) Use the delete_elem_from_vector function we give you!
 * 3) Remember to write the CSV column headers at the beginning of the output!
 *    See courses.csv for reference.
 *
 * @param all_courses A vector of all courses gotten by calling `parse_csv`.
 *                    This vector will be modified by removing all offered courses.
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  // 1. 打开用于输出的文件
std::ofstream outfile("student_output/courses_offered.csv");

// 2. 写入 CSV 文件的表头
outfile << "Title,Number of Units,Quarter\n";

// 3. 创建一个临时的向量，用来存放未开设的课程
std::vector<Course> unlisted_courses;

// 4. 遍历所有传入的课程
for (const Course& course : all_courses) {
    // 5. 检查课程是否已开设
    if (course.quarter != "null") {
        // 如果是，就把它写入到输出文件中
        outfile << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
    } else {
        // 如果不是（即未开设），就把它存入我们的临时向量中
        unlisted_courses.push_back(course);
    }
}

// 6. 循环结束后，用只包含“未开设”课程的临时向量，来覆盖掉原来的 all_courses 向量。
//    这就巧妙地完成了“删除”已开设课程的操作。
all_courses = unlisted_courses;
}
 /* HINT: This should be VERY similar to `write_courses_offered`
 *
 * @param unlisted_courses A vector of courses that are not offered.
 */


void write_courses_not_offered(std::vector<Course>& unlisted_courses) {
  // 1. 创建文件输出流，打开要写入的文件。
//    根据作业要求，文件名是固定的。
std::ofstream outfile("student_output/courses_not_offered.csv");

// 2. 写入 CSV 文件的表头。
outfile << "Title,Number of Units,Quarter\n";

// 3. 遍历向量中的每一门课程。
//    因为这个向量里已经只剩下未开设的courses了，所以我们不需要再做任何判断。
for (const Course& course : unlisted_courses) {
    // 4. 将课程信息按 CSV 格式写入文件。
    outfile << course.title << "," << course.number_of_units << "," << course.quarter << "\n";
}
}
// 函数结束时，文件会自动关闭。


int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}
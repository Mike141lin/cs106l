// user.h

#include <iostream>
#include <string>

class User {
public:
    // -- 这是课程提供的原始函数 --
    User(const std::string& name);
    void add_friend(const std::string& name);
    std::string get_name() const;
    size_t size() const;
    void set_friend(size_t index, const std::string& name);

    // ======== 学生需要添加/修改的部分 ========

    // Part 1: 打印运算符 (友元函数)
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    // Part 2: 特殊成员函数
    ~User();                                  // 1. 析构函数
    User(const User& other);                  // 2. 拷贝构造函数
    User& operator=(const User& other);       // 3. 拷贝赋值运算符
    User(User&& other) = delete;              // 4. 移动构造函数 (已删除)
    User& operator=(User&& other) = delete;   // 5. 移动赋值运算符 (已删除)

    // Part 3: 其他重载运算符 (成员函数)
    User& operator+=(User& rhs);
    bool operator<(const User& rhs) const;

private:
    std::string _name;
    std::string* _friends;
    size_t _size;
    size_t _capacity;
};

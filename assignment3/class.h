#ifndef PET_H  // 这些是“头文件保护”，防止重复包含
#define PET_H

#include <string>

class Pet {
public:
    // 要求 2: 默认构造函数
    Pet();

    // 要求 1: 自定义构造函数
    Pet(std::string name, std::string species, int age);

    // 要求 5: 公共 getter 函数 (标记为 const)
    std::string getName() const;
    int getAge() const;

    // 要求 6: 公共 setter 函数
    void setName(std::string new_name);

private:
    // 要求 3: 私有成员字段
    std::string name;
    std::string species;
    int age;

    // 要求 4: 私有成员函数
    bool is_birthday_valid(int month, int day);
};

#endif

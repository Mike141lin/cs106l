#include "class.h" // 包含头文件，让 .cpp 文件知道类的声明
#include <iostream>

// 要求 2: 默认构造函数的实现
Pet::Pet() {
    name = "Unnamed";
    species = "Unknown";
    age = 0;
    std::cout << "A default pet has been created!\n";
}

// 要求 1: 自定义构造函数的实现
Pet::Pet(std::string pet_name, std::string pet_species, int pet_age) {
    name = pet_name;
    species = pet_species;
    age = pet_age;
    std::cout << name << " the " << species << " has been created!\n";
}

// 要求 5: getter 函数的实现
std::string Pet::getName() const {
    return name;
}

int Pet::getAge() const {
    return age;
}

// 要求 6: setter 函数的实现
void Pet::setName(std::string new_name) {
    name = new_name;
}

// 要求 4: 私有成员函数的实现
bool Pet::is_birthday_valid(int month, int day) {
    // 这是一个示例私有函数，可以用来做一些内部逻辑检查
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    return true;
}

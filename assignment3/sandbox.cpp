#include "class.h" // 包含你的类头文件
#include <iostream>

void sandbox() {
    // 创建一个你的类的实例
    // 比如，使用自定义构造函数创建一个 Pet 对象
    Pet my_dog("Fido", "Dog", 5);

    // 使用 getter 函数
    std::cout << "My dog's name is: " << my_dog.getName() << std::endl;

    // 使用 setter 函数
    my_dog.setName("Buddy");
    std::cout << "My dog's new name is: " << my_dog.getName() << std::endl;

    // 使用默认构造函数创建另一个对象
    Pet mystery_pet;
}

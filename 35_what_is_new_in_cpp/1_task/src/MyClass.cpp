#include "MyClass.h"

MyClass::MyClass(std::initializer_list<int> inValue) {
    values = inValue;
}

void MyClass::print() {
    for (auto& i : values) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


#pragma  once

#include <iostream>
#include <vector>

class MyClass {
public:
    MyClass(std::initializer_list<int> inValue);
    void print();
private:
    std::vector<int> values;
};


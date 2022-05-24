#pragma once

#include "SmartPtrToy.h"

class Dog {
public:
    Dog(const std::string& inName, const std::string& toyName, const int& inAge);
    Dog();
    Dog(const std::string& inName);
    Dog(const int& inAge);
private:
    std::string name;
    int age;
    SmartPtrToy lovelyToy;
};

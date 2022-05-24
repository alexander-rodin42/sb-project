#include <iostream>

#include "Dog.h"

Dog::Dog(const std::string& inName, const std::string& toyName, const int& inAge) : name(inName), lovelyToy(toyName) {
    if (inAge >= 0 && inAge < 30) {
        age = inAge;
    } else {
        age = 0;
    }
}

Dog::Dog() : Dog("Snow", "SomeToy", 0) {}

Dog::Dog(const std::string &inName) : Dog(inName, "SomeToy", 0) {}

Dog::Dog(const int &inAge) : Dog("Snow", "SomeToy", inAge) {}

#include <iostream>

#include "SmartPtrToy.h"

SmartPtrToy::SmartPtrToy()  {
    obj = new Toy();
}

SmartPtrToy::SmartPtrToy(const std::string& name) {
    obj = new Toy(name);
}

SmartPtrToy::SmartPtrToy(const SmartPtrToy& other) {
    obj = new Toy(*other.obj);
}

SmartPtrToy &SmartPtrToy::operator= (const SmartPtrToy& other) {
    if (this == &other) {
        return *this;
    }
    if (this != nullptr) {
        delete obj;
    }
    obj = new Toy(*other.obj);
    return *this;
}

SmartPtrToy::~SmartPtrToy() {
    delete obj;
}


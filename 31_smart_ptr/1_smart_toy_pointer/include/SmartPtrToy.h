#pragma once

#include "Toy.h"

class SmartPtrToy {
public:
    SmartPtrToy();
    SmartPtrToy(const std::string& name);
    SmartPtrToy(const SmartPtrToy& other);
    SmartPtrToy& operator= (const SmartPtrToy& other);
    ~SmartPtrToy();
private:
    Toy* obj{};
};

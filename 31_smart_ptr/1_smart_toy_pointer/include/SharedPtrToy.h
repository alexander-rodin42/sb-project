#pragma once

#include "Toy.h"

class SharedPtrToy {
public:
    SharedPtrToy();
    SharedPtrToy(const std::string& name);
    SharedPtrToy(const SharedPtrToy& other);
    SharedPtrToy& operator= (const SharedPtrToy& other);
    ~SharedPtrToy();

    void reset();
    void swap(SharedPtrToy& other);
    Toy* get();
    Toy operator* ();
    Toy* operator-> ();
    int use_count();
    bool unique();
    operator bool();
    bool owner_before(const SharedPtrToy& other);
private:
    Toy* obj = nullptr;
    int* referenceCount = nullptr;
};


#include <iostream>
#include <algorithm>

#include "SharedPtrToy.h"

SharedPtrToy::SharedPtrToy() {
    obj = new Toy();
    referenceCount = new int(1);
}

SharedPtrToy::SharedPtrToy(const std::string &name) {
    obj = new Toy(name);
    referenceCount = new int(1);
}

SharedPtrToy::SharedPtrToy(const SharedPtrToy &other) {
    obj = other.obj;
    referenceCount = other.referenceCount;
    *referenceCount += 1;
}

SharedPtrToy& SharedPtrToy::operator=(const SharedPtrToy &other) {
    if (this == &other) {
        return *this;
    }

    if (this != nullptr) {
        if (*referenceCount <= 1) {
            std::cout << obj->getName() << " deleted." << std::endl;
            delete obj;
        }
        else {
            *referenceCount -= 1;
        }
        obj = other.obj;
        referenceCount = other.referenceCount;
        *referenceCount += 1;
    }
    return *this;
}

SharedPtrToy::~SharedPtrToy() {
    if (obj != nullptr) {
        *referenceCount -= 1;
        if (*referenceCount == 0) {
            std::cout << obj->getName() << " deleted." << std::endl;
            delete obj;
            delete referenceCount;
        }
    }
}

void SharedPtrToy::reset() {
    if (*referenceCount <= 1) {
        std::cout << obj->getName() << " deleted." << std::endl;
        delete obj;
    }
    else {
        *referenceCount -= 1;
    }
    obj = nullptr;
    referenceCount = nullptr;
}

void SharedPtrToy::swap(SharedPtrToy &other) {
    std::swap(this->obj, other.obj);
    std::swap(this->referenceCount, other.referenceCount);
}

Toy *SharedPtrToy::get() {
    return obj;
}

int SharedPtrToy::use_count() {
    if (obj == nullptr) {
        return 0;
    }
    else {
        return *referenceCount;
    }
}

Toy SharedPtrToy::operator*() {
    return *obj;
}

Toy* SharedPtrToy::operator->() {
    return obj;
}

bool SharedPtrToy::unique() {
    return obj != nullptr && *referenceCount == 1;
}

SharedPtrToy::operator bool() {
    return obj != nullptr;
}

bool SharedPtrToy::owner_before(const SharedPtrToy& other) {
    return this->obj == other.obj;
}



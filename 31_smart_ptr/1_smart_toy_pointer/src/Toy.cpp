#include <iostream>

#include "Toy.h"

Toy::Toy(const std::string& inName) : name(inName) {}

Toy::Toy() : name("SameToy") {}

std::string Toy::getName() {
    return name;
};

#pragma once

#include <iostream>
#include <vector>

class Employee {
public:
    void setRandomName();
    void setName(std::string& inName);
    std::string getName();
private:
    std::string fullName = "no fullName";
    static std::vector<std::string> firstNames;
    static std::vector<std::string> secondNames;
};


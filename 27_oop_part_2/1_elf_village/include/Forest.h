#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Branch.h"

class Forest {
public:
    explicit Forest(const int& inTreeCount);
    void placeTheElves();
    std::map<std::string, std::vector<Branch*>>& getList();
    void print();

private:
    int treeCount = 5;
    Branch** forest = nullptr;
    std::map<std::string, std::vector<Branch*>> list{};

    void fillList();
};


#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "Branch.h"

class Forest {
public:
    explicit Forest(const int& inTreeCount);
    void placeTheElves();
    void printTrees();
    void printList();
    void findElf(std::string& name);

private:
    int treeCount = 5;
    Branch** forest = nullptr;
    std::map<std::string, std::vector<Branch*>> list{};

    void fillList();
};


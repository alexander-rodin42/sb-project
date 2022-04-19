#pragma once

#include <iostream>
#include <vector>
#include <map>

enum branchTypes {
    TREE = 1,
    BIG_BRANCH = 2,
    MIDDLE_BRANCH = 3
};

class Branch {
public:
    explicit Branch(Branch* inParent = nullptr, const int& inType = TREE);
    void placeTheElves();
    void print();
    static void printAddress(Branch* branch);

private:
    int number = 0;
    int branchType = TREE;
    int childBranchCount = 0;
    Branch* parent = nullptr;
    Branch** childBranch = nullptr;
    std::string elfName = "None";
};


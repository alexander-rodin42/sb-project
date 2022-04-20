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
    explicit Branch(const int& inNumber, Branch* inParent = nullptr, const int& inType = TREE);
    void placeTheElves();
    void print();
    void doCensus(std::map<std::string, std::vector<Branch*>>& list);
    int getNumberOfNeighbors();

    static void printAddress(Branch* branch);

private:
    int number = 0;
    int branchType = TREE;
    int childBranchCount = 0;
    Branch* parent = nullptr;
    Branch** childBranch = nullptr;
    std::string elfName = "None";

    int getNumberElvesOnChildBranches();
};


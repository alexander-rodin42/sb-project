#include <cassert>

#include "Branch.h"
#include "Verification.h"

Branch::Branch(Branch* inParent, const int& inType) : parent(inParent), branchType(inType) {
    assert(inType > 0 && inType <= 3);

    if (inType == TREE) {
        childBranchCount = 3 + std::rand() % 3;
    }
    else if (inType == BIG_BRANCH) {
        childBranchCount = 2 + std::rand() % 2;
    }

    if (inType != MIDDLE_BRANCH) {
        childBranch = new Branch*[childBranchCount];
        for (int i = 0; i < childBranchCount; ++i) {
            childBranch[i] = new Branch(this, inType + 1);
            childBranch[i]->number = i + 1;
        }
    }
}

void Branch::placeTheElves() {
    if (branchType != TREE) {
        do {
            std::cout << "-> Enter elf name: ";
            std::cin >> elfName;
        }
        while (!CheckName(elfName));
        ConvertNameToFormat(elfName);
    }

    if (branchType != MIDDLE_BRANCH) {
        assert(childBranch != nullptr);

        for (int i = 0; i < childBranchCount; ++i) {
            if (childBranch[i]->branchType == BIG_BRANCH) {
                std::cout << "Big branch " << i + 1 << std::endl;
            }
            else if (childBranch[i]->branchType == MIDDLE_BRANCH) {
                std::cout << "Middle branch " << i + 1 << std::endl;
            }
            childBranch[i]->placeTheElves();
        }
        std::cout << std::endl;
    }
}

void Branch::print() {
    if (branchType != MIDDLE_BRANCH) {
        assert(childBranch != nullptr);

        for (int i = 0; i < childBranchCount; ++i) {
            if (childBranch[i]->branchType == BIG_BRANCH) {
                std::cout << "Big branch " << i + 1 << " - " << childBranch[i]->elfName << std::endl;
            }
            else if (childBranch[i]->branchType == MIDDLE_BRANCH) {
                std::cout << "Middle branch " << i + 1 << " - " << childBranch[i]->elfName << std::endl;
            }
            childBranch[i]->print();
        }
        std::cout << std::endl;
    }
}

void Branch::printAddress(Branch *branch) {
    if (branch->branchType == MIDDLE_BRANCH) {
        branch->printAddress(branch->parent);
        std::cout << "middle branch " << branch->number << " ";
    }
    else if (branch->branchType == BIG_BRANCH) {
        branch->printAddress(branch->parent);
        std::cout << "big branch " << branch->number << " ";
    }
    else if (branch->branchType == TREE) {
        std::cout << "Tree " << branch->number << " ";
    }
}

void Branch::doCensus(std::map<std::string, std::vector<Branch *>>& list) {
    if (elfName != "None") {
        list[elfName].emplace_back(this);
    }

    if (branchType != MIDDLE_BRANCH) {
        assert(childBranch != nullptr);

        for (int i = 0; i < childBranchCount; ++i) {
            childBranch[i]->doCensus( list);
        }
    }
}






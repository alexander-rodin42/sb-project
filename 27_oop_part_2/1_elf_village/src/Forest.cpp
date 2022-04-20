#include <cassert>

#include "Forest.h"

Forest::Forest(const int& inTreeCount) : treeCount(inTreeCount) {
    assert(inTreeCount > 0);

    forest = new Branch*[inTreeCount];
    for (int i = 0; i < inTreeCount; ++i) {
        forest[i] = new Branch(i + 1);
        std::cout << std::endl;
    }
}

void Forest::placeTheElves() {
    for (int i = 0; i < treeCount; ++i) {
        std::cout << "Tree No." << i + 1 << std::endl;
        forest[i]->placeTheElves();
    }

    this->fillList();
}

void Forest::printTrees() {
    for (int i = 0; i < treeCount; ++i) {
        std::cout << "Tree No." << i + 1 << std::endl;
        forest[i]->print();
    }
}

void Forest::printList() {
    for (auto & i : list) {
        std::cout << i.first << ":" << std::endl;
        for (auto & j : i.second) {
            Branch::printAddress(j);
            std::cout << std::endl;
        }
    }
}

void Forest::fillList() {
    for (int i = 0; i < treeCount; ++i) {
        forest[i]->doCensus(list);
    }
}

void Forest::findElf(std::string &name) {
    if (list.find(name) == list.end()) {
        std::cout << "Elf named " << name << " not found." << std::endl;
    }
    else {
        std::cout << "Found elves named " << name << ": " << list[name].size() << std::endl;
        for (auto & i : list[name]) {
            std::cout << "An elf living at address: ";
            Branch::printAddress(i);
            std::cout << ", has " << i->getNumberOfNeighbors() << " neighbors." << std::endl;

        }
        std::cout << std::endl;
    }
}






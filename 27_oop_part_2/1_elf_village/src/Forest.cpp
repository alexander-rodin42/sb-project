#include <cassert>

#include "Forest.h"

Forest::Forest(const int& inTreeCount) : treeCount(inTreeCount) {
    assert(inTreeCount > 0);

    forest = new Branch*[inTreeCount];
    for (int i = 0; i < inTreeCount; ++i) {
        forest[i] = new Branch();
        std::cout << std::endl;
    }
}



void Forest::placeTheElves() {
    for (int i = 0; i < treeCount; ++i) {
        std::cout << "Tree No." << i + 1 << std::endl;
        forest[i]->placeTheElves();
    }
}

void Forest::print() {
    for (int i = 0; i < treeCount; ++i) {
        std::cout << "Tree No." << i + 1 << std::endl;
        forest[i]->print();
    }

    for (auto & i : list) {
        std::cout << i.first << std::endl;
    }
}




void Forest::fillList() {
    for (int i = 0; i < treeCount; ++i) {

    }
}

std::map<std::string, std::vector<Branch *>>& Forest::getList() {
    return list;
}

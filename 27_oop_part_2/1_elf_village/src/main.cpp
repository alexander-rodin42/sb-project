#include <iostream>
#include <ctime>

#include "Branch.h"

int main() {
    std::srand(std::time(nullptr));

    auto* branch = new Branch();

    branch->placeTheElves();
    branch->print();

    std::cout << "_____________" << std::endl;

    delete branch;

    return 0;
}

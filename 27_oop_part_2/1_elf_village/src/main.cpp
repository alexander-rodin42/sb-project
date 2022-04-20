#include <iostream>
#include <ctime>

#include "Branch.h"
#include "Forest.h"

int main() {
    std::srand(std::time(nullptr));

//    auto* branch = new Branch();
//
//    branch->placeTheElves();
//    branch->print();
//
//    std::cout << "_____________" << std::endl;
//
//    delete branch;

    auto* forest = new Forest(2);

    forest->placeTheElves();

    forest->print();

    delete forest;

    return 0;
}

#include <iostream>
#include <ctime>

#include "Branch.h"
#include "Forest.h"
#include "Verification.h"

void Input(std::string& input) {
    do {
        std::cout << "Enter elf name: ";
        std::cin >> input;
    } while (!CheckName(input));
    ConvertNameToFormat(input);
}

int main() {
    std::srand(std::time(nullptr));
    auto* forest = new Forest(5);
    forest->placeTheElves();

    std::string input;

    do {
        std::cout << "Available commands: Exit." << std::endl;
        Input(input);
        if (input != "Exit") {
            forest->findElf(input);
        }
    } while (input != "Exit");

    //forest->printTrees();
    //forest->printList();

    delete forest;

    return 0;
}

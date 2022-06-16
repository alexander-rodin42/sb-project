#include <iostream>

#include "Registry.h"

void InputCommand (std::string& command) {
    do {
        std::cout << "Enter the command: ";
        std::cin >> command;
    }
    while (!(command == "add" ||
             command == "remove" ||
             command == "print" ||
             command == "find" ||
             command == "exit"));
}

template<typename T>
T input(const std::string& message) {
    std::cout << message;
    T result;
    std::cin >> result;
    return result;
}

int main() {
    Registry<int, std::string> registry;
    std::cout << "Available commands: add, remove, print, find, exit." << std::endl;
    std::string command;

    do {
        InputCommand( command);

        if (command == "add") {
            registry.add(input<int>("Enter key(int): "), input<std::string>("Enter value(string): "));
        }
        else if (command == "remove") {
            registry.remove(input<int>("Enter key(int): "));
        }
        else if (command == "print") {
            registry.print();
        }
        else if (command == "find") {
            std::vector<std::string> searchResults = registry.find(input<int>("Enter key(int): "));

            std::cout << "Found " << searchResults.size() << " values:" << std::endl;
            for (auto & i : searchResults) {
                std::cout << i << std::endl;
            }
        }
    }
    while (command != "exit");

    return 0;
}

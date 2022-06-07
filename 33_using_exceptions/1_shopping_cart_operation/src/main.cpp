#include <iostream>
#include <map>

#include "Basket.h"

void InputCommand (std::string& command) {
    do {
        std::cout << "Enter the command: ";
        std::cin >> command;

        if (!(command == "add" || command == "remove" || command == "print" || command == "exit")) {
            std::cout << "Invalid command." << std::endl;
        }
    }
    while (!(command == "add" ||
             command == "remove" ||
             command == "print" ||
             command == "exit"));
}

template<typename T>
T input(const std::string& message) {
    T result;
    std::cout << message;
    (std::cin >> result).get();
    return result;
}

int main() {
    Basket basket;
    basket.printDatabase();

    std::string command;
    do {
        std::cout << std::endl << "Available commands: add, remove, print, exit." << std::endl;
        InputCommand( command);

        try {
            if (command == "add") {
                std::string vendorCode = input<std::string>("Enter product code to add to cart: ");
                int amount = input<int>("Enter quantity of product: ");
                basket.add(vendorCode, amount);
            }
            else if (command == "remove") {
                std::string vendorCode = input<std::string>("Enter product code to remove from cart: ");
                int amount = input<int>("Enter quantity of product: ");
                basket.remove(vendorCode, amount);
            }
            else if (command == "print") {
                basket.printShoppingCart();
            }
        }
        catch (const std::exception& x) {
            std::cerr << x.what() << std::endl;
        }
    }
    while (command != "exit");

    return 0;
}

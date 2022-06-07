#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

#include "Basket.h"

Basket::Basket() {
    try {
        int productTypesNumber = Basket::inputProductTypesNumber();

        while (database.size() < productTypesNumber) {
            try {
                std::string vendorCode = Basket::inputVendorCode();
                database[vendorCode] = Basket::inputProductQuantity();
            }
            catch (const std::exception& x) {
                std::cerr << x.what() << std::endl;
            }
        }
    }
    catch (const std::exception& x) {
        std::cout << x.what() << std::endl;
    }
}

bool Basket::checkVendorCode(const std::string &vendorCode) {
    return std::all_of(vendorCode.begin(), vendorCode.end(), [](char i){return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z' || i >= '0' && i <= '9' || i == '_';});
}

std::string Basket::inputVendorCode() {
    std::string result;
    std::cout << "Enter the article number: ";
    std::getline(std::cin, result);

    if (!Basket::checkVendorCode(result)) {
        throw std::invalid_argument("The product code can only consist of Latin letters (a-z, A-Z), numbers (0-9) and the special character \"_\".");
    }
    return result;
}

int Basket::inputProductQuantity() {
    int result;
    std::cout << "Enter the quantity of goods in stock: ";
    (std::cin >> result).get();

    if (result < 0) {
        throw std::invalid_argument("The number of items in stock cannot be less than zero.");
    }
    return result;
}

int Basket::inputProductTypesNumber() {
    int result;
    std::cout << "Enter the number of types of goods in stock: ";
    (std::cin >> result).get();

    if (result <= 0) {
        throw std::invalid_argument("The number of types of goods must be at least one.");
    }
    return result;
}

void Basket::printDatabase() const {
    if (database.empty()) {
        throw std::runtime_error("Product database is empty.");
    }
    else {
        for (auto & i : database) {
            std::cout << i.first << " - " << i.second << " pcs." << std::endl;
        }
    }
}

void Basket::printShoppingCart() const {
    if (shoppingCart.empty()) {
        throw std::runtime_error("Cart is empty.");
    }
    else {
        std::cout << "Cart contents:" << std::endl;
        for (auto & i : shoppingCart) {
            std::cout << i.first << " - " << i.second << " pcs." << std::endl;
        }
    }

}

void Basket::add(const std::string &vendorCode, const int &amount) {
    if (amount <= 0) {
        throw std::invalid_argument("The quantity of goods cannot be less than one.");
    }
    if (database.find(vendorCode) == database.end()) {
        throw std::invalid_argument("Product with code " + vendorCode + " not found.");
    }
    if (database.find(vendorCode)->second < amount ||
            (shoppingCart.find(vendorCode) != shoppingCart.end() && shoppingCart.find(vendorCode)->second + amount > database.find(vendorCode)->second)) {
        throw std::runtime_error("Not enough items in stock.");
    }

    if (shoppingCart.find(vendorCode) != shoppingCart.end()) {
        shoppingCart.find(vendorCode)->second += amount;
    }
    else {
        shoppingCart[vendorCode] = amount;
    }
}

void Basket::remove(const std::string &vendorCode, const int &amount) {
    if (amount <= 0) {
        throw std::invalid_argument("The quantity of goods cannot be less than one.");
    }
    if (shoppingCart.find(vendorCode) == shoppingCart.end()) {
        throw std::invalid_argument("The product with the code " + vendorCode + " is not in the cart.");
    }
    if (shoppingCart.find(vendorCode)->second < amount) {
        throw std::runtime_error("It is not possible to remove more items from the cart than not available.");
    }

    shoppingCart.find(vendorCode)->second -= amount;

    if (shoppingCart.find(vendorCode)->second == 0) {
        shoppingCart.erase(vendorCode);
    }
}







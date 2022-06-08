#pragma once

#include <iostream>
#include <map>

class Basket {
public:
    Basket();

    void printDatabase() const;
    void printShoppingCart() const;

    void add(const std::string& vendorCode, const int& amount);
    void remove(const std::string& vendorCode, const int& amount);

private:
    std::map<std::string, int> database;
    std::map<std::string, int> shoppingCart;

    static bool checkVendorCode(const std::string& vendorCode);
    static std::string inputVendorCode();
    static int inputProductQuantity();
    static int inputProductTypesNumber();
};


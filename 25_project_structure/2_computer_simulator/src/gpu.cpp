#include <iostream>
#include <string>
#include "gpu.h"
#include "ram.h"

void display(const std::string& message, const bool& lineBreak) {
    if (lineBreak) {
        std::cout << message << std::endl;
    } else {
        std::cout << message;
    }

}

void display(const int& value) {
    std::cout << value << std::endl;
}

void display(Buffer& buffer) {
    if (buffer.empty()) {
        display("RAM is empty.", true);
    }
    else {
        for (int i = 0; i < 8; ++i) {
            std::cout << buffer.read(i) << " ";
        }
        std::cout << std::endl;
    }
}
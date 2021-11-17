#include <iostream>
#include <string>

int main() {
    std::string apartmentNumber[10];

    for (int i = 0; i < 10; i++) {
        std::cout << "Enter the name of the tenant of the apartment N" << i + 1 << ": ";
        std::cin >> apartmentNumber[i];
    }
    for (int i = 0; i < 3; i++) {
        int userInput;
        do {
            std::cout << "Enter apartment number (1-10): ";
            std::cin >> userInput;
        } while (userInput < 1 || userInput > 10);

        std::cout << "In apartment N" << userInput << " lives " << apartmentNumber[userInput - 1] << std::endl;
    }
    return 0;
}

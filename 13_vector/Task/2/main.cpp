#include <iostream>
#include <vector>

int main() {
    int amountNumbers;

    std::cout << "Enter amount of numbers: ";
    std::cin >> amountNumbers;

    std::vector<float> numbers(amountNumbers);

    for (int i = 0; i < amountNumbers; i++) {
        std::cout << i << " - ";
        std::cin >> numbers[i];
    }

    for (int i = amountNumbers - 1; i >= 0; i--) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}

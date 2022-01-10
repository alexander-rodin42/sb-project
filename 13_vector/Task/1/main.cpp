#include <iostream>
#include <vector>

int main() {
    int amountNumbers;
    int sum = 0;

    std::cout << "Enter the number of numbers: ";
    std::cin >> amountNumbers;

    std::vector<int> numbers(amountNumbers);

    for (int i = 0; i < amountNumbers; i++) {
        std::cout << i << " - ";
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    std::cout << "The sum is equal to: " << sum;

    return 0;
}

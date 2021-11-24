#include <iostream>
#include <vector>

int main() {
    int amountNumber;

    do {
        std::cout << "Enter amount of number (n > 1): ";
        std::cin >> amountNumber;
    } while (amountNumber < 2);

    std::vector<int> numbers( amountNumber);

    for (int i = 0; i < amountNumber; i++) {
        std::cout << i << " - ";
        std::cin >> numbers[i];
    }

    int largestNumber = numbers[0];
    int secondLargestNumber = numbers[1];

    for (int i = 0; i < amountNumber; i++) {
        if (numbers[i] > largestNumber) {
            secondLargestNumber = largestNumber;
            largestNumber = numbers[i];
        }
    }

    for (int i = 0; i < amountNumber; i++) {
        if (numbers[i] > secondLargestNumber && numbers[i] < largestNumber) {
            secondLargestNumber = numbers[i];
        }
    }

    std::cout << "The second largest number is: " << secondLargestNumber;

     return 0;
}

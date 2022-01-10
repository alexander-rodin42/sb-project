#include <iostream>
#include <vector>

//std::vector<int> RemoveNumbers (const std::vector<int>& numbers, int deleteNumbers) {
//    std::vector<int> result;
//
//    for (int number : numbers) {
//        if (number != deleteNumbers) {
//            result.push_back(number);
//        }
//    }
//    return result;
//}

void RemoveNumbers (std::vector<int>& numbers, int deleteNumbers) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == deleteNumbers) {
            numbers.erase( numbers.begin() + i);
            i--;
        }
    }
}

void printVector (const std::vector<int>& vector) {
    for (int number : vector) {
        std::cout << number << " ";
    }
}

int main() {
    int amountNumbers;
    int deleteNumber;

    do {
        std::cout << "Enter digits of number:";
        std::cin >> amountNumbers;
    } while (amountNumbers < 0);

    std::vector<int> numbers( amountNumbers);

    for (int i = 0; i < amountNumbers; i++) {
        std::cout << "Enter number #" << i << ": ";
        std::cin >> numbers[i];
    }

    std::cout << "Enter the number to remove:";
    std::cin >> deleteNumber;

    RemoveNumbers( numbers, deleteNumber);

    if (numbers.empty()) {
        std::cout << "Vector is empty." << std::endl;
    } else {
        printVector( numbers);
    }

    return 0;
}

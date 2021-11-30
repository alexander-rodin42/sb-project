#include <iostream>
#include <vector>

int main() {
    const int maximumCapacity = 20;
    std::vector<int> dataBase( maximumCapacity);
    int userInput;
    int index = 0;

    std::cout << "Enter the number: ";
    std::cin >> userInput;

    do {
        if (index == maximumCapacity) {
            index = 0;
        }

        dataBase[index] = userInput;
        index++;

        std::cout << "Enter the number: ";
        std::cin >> userInput;

    } while (userInput != -1);

    for (int i = 0; i < maximumCapacity; i++) {
        if (index == maximumCapacity) {
            index = 0;
        }

        std::cout << dataBase[index] << " ";
        index++;
    }
    return 0;
}

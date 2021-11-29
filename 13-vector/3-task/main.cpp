#include <iostream>
#include <vector>

int main() {
    std::vector<int> dataBase;
    int userInput;
    const int maximumCapacity = 20;

    std::cout << "Enter the number: ";
    std::cin >> userInput;

    do {
        if (dataBase.size() < maximumCapacity) {
            dataBase.push_back(userInput);
        } else {
            for (int i = 1; i < maximumCapacity; i++) {
                dataBase[i - 1] = dataBase[i];
            }
            dataBase[maximumCapacity - 1] = userInput;
        }

        std::cout << "Enter the number: ";
        std::cin >> userInput;

    } while (userInput != -1);

    for (int number : dataBase) {
        std::cout << number << " ";
    }
    return 0;
}

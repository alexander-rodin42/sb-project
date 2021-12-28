#include <iostream>
#include <vector>

int UserInput () {
    int input;

    do {
        std::cout << R"(Enter a number greater than zero (or "-1" to print the fifth highest number, -2 to exit): )";
        std::cin >> input;
        std::cout << std::endl;

    } while (input == 0 || input < -2);

    return input;
}

void SortVector (std::vector<int>& numbers) {
    for (int i = numbers.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            int temp;
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void PrintVector (const std::vector<int>& numbers) {
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers;
    int number = 0;

    do {
        number = UserInput();

        if (number > 0) {
            numbers.push_back(number);
        } else if (number == -1) {
            SortVector( numbers);
            //PrintVector( numbers);

            if (numbers.size() >= 5) {
                std::cout << numbers[4] << std::endl;
            }
        }
    } while (number != -2);

    return 0;
}

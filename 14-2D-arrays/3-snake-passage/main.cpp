#include <iostream>

int main() {
    int numbers[5][5];
    int currentNumber = 0;
    bool directSequence = true;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 && directSequence; j++) {
            numbers[i][j] = currentNumber;
            currentNumber++;
        }
        for (int j = 4; j >= 0 && !directSequence; j--) {
            numbers[i][j] = currentNumber;
            currentNumber++;
        }
        directSequence = !directSequence;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

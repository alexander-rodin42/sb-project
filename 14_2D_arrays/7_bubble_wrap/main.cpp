#include <iostream>

void RefreshBubbles (bool (&bubbles)[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            bubbles[i][j] = true;
        }
    }
}

void PrintBubbles (bool (&bubbles)[12][12]) {
    std::cout << "  Y" << std::endl << "  ^" << std::endl;
    for (int i = 11; i >= 0; i--) {
        if (i < 9) {
            std::cout << " ";
        }
        std::cout << i + 1 << "| ";

        for (int j = 0; j < 12; j++) {
            if (bubbles[i][j]) {
                std::cout << "O  ";
            } else {
                std::cout << "X  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "  +------------------------------------> X" << std::endl;
    std::cout << "    1  2  3  4  5  6  7  8  9  10 11 12" << std::endl;
}

int InputCoordinate (const std::string& message) {
    int coordinate;
    do {
        std::cout << message;
        std::cin >> coordinate;
    } while (coordinate < 1 || coordinate > 12);

    return coordinate - 1;
}

void UserInput (int& minX, int& minY, int& maxX, int& maxY) {

        minX = InputCoordinate("Enter the X coordinate for the first point (from 1 to 12): ");
        minY = InputCoordinate("Enter the Y coordinate for the first point (from 1 to 12): ");
        maxX = InputCoordinate("Enter the X coordinate for the second point (from 1 to 12): ");
        maxY = InputCoordinate("Enter the Y coordinate for the second point (from 1 to 12): ");

    if (minX > maxX) {
        int temporaryVariable = minX;
        minX = maxX;
        maxX = temporaryVariable;
    }
    if (minY > maxY) {
        int temporaryVariable = minY;
        minY = maxY;
        maxY = temporaryVariable;
    }
}

void BurstBubbles (bool (&bubbles)[12][12]) {
    int numberBubblesBurst = 0;

    do {
        PrintBubbles( bubbles);

        int minX, minY, maxX, maxY;
        UserInput( minX, minY, maxX, maxY);

        for (int i = minY; i <= maxY; i++) {
            for (int j = minX; j <= maxX; j++) {
                if (bubbles[i][j]) {
                    bubbles[i][j] = false;
                    std::cout << j + 1 << " " << i + 1 << " - " << "Pop!" << std::endl;
                    numberBubblesBurst++;
                }
            }
        }
    } while (numberBubblesBurst < 144);
}

int main() {
    bool bubbles [12][12];

    RefreshBubbles( bubbles);
    BurstBubbles( bubbles);
    PrintBubbles( bubbles);

    std::cout << "It's done, the bubbles are over!" << std::endl;

    return 0;
}

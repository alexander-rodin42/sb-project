#include <iostream>

int UserInput (int& coordinateX, int& coordinateY) {
    int height;
    do {
        std::cout << "Enter the column height " << coordinateX + 1 << ", " << coordinateY + 1 << " (from 0 to 10): ";
        std::cin >> height;
    } while (height < 0 || height > 10);

    return height - 1;
}

int UserInput () {
    std::string axis;
    int input;
    bool inputCorrect;

    do {
        std::cout << "To exit enter \"exit\"" << std::endl;
        std::cout << "Enter the coordinate axis (x or y): ";
        std::cin >> axis;

        inputCorrect = axis == "x" || axis == "y" || axis == "exit";
    } while (!inputCorrect);

    if (axis == "exit") {
        return -1;
    }

    do {
        std::cout << "Enter the section number (from 1 to 5): ";
        std::cin >> input;

        inputCorrect = input > 0 && input <= 5;
    } while (!inputCorrect);

    if (axis == "x") {
        return input + 9;
    } else {
        return input + 19;
    }
}

void InitializeLandscape (bool (&landscape)[5][5][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int height = UserInput( j, i);

            for (int k = 0; k < 10; k++) {
                if (k <= height) {
                    landscape[i][j][k] = true;
                } else {
                    landscape[i][j][k] = false;
                }
            }
        }
    }
}

void PrintTopView (bool (&landscape)[5][5][10]) {
    std::cout << std::endl;
    std::cout << " y   Top view" << std::endl;
    std::cout << " ^" << std::endl;

    for (int i = 4; i >= 0; i--) {
        std::cout << i + 1 << "| ";

        for (int j = 0; j < 5; j++) {
            int height = 0;

            while ( landscape[i][j][height]) {
                height++;
            }
            if (height > 9) {
                std::cout << height << " ";
            } else {
                std::cout << height << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << " +--------------> x" << std::endl;
    std::cout << "   1  2  3  4  5" << std::endl;
    std::cout << std::endl;
}

void PrintView (bool (&landscape)[5][5][10], int currentSection) {
    if (currentSection > 20) {
        currentSection %= 10;

        std::cout << std::endl;
        std::cout << "  z  Front view" << std::endl;
        std::cout << "  ^" << std::endl;

        for (int z = 9; z >= 0; z--) {
            if (z == 9) {
                std::cout << z + 1 << "| ";
            } else {
                std::cout << z + 1 << " | ";
            }

            for (int x = 0; x < 5; x++) {
                if (landscape[currentSection][x][z]) {
                    std::cout << "X  ";
                } else {
                    std::cout << "0  ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "  +--------------> x" << std::endl;
        std::cout << "    1  2  3  4  5" << std::endl;
        std::cout << std::endl;
    } else {
        currentSection %= 10;

        std::cout << std::endl;
        std::cout << "  z   Right view" << std::endl;
        std::cout << "  ^" << std::endl;

        for (int z = 9; z >= 0; z--) {
            if (z == 9) {
                std::cout << z + 1 << "| ";
            } else {
                std::cout << z + 1 << " | ";
            }

            for (int y = 0; y < 5; y++) {
                if (landscape[y][currentSection][z]) {
                    std::cout << "X  ";
                } else {
                    std::cout << "0  ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "  +--------------> y" << std::endl;
        std::cout << "    1  2  3  4  5" << std::endl;
        std::cout << std::endl;
    }
}

void BuildSection (bool (&landscape)[5][5][10]) {
    int section;

    do {
        PrintTopView( landscape);

        section = UserInput();

        if (section > 0) {
            PrintView( landscape, section);
        }
    } while (section > 0);
}

int main() {
    bool landscape [5][5][10];

    InitializeLandscape( landscape);
    BuildSection( landscape);

    return 0;
}

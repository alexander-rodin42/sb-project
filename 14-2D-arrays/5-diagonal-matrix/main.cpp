#include <iostream>

void InputData (int (&matrix)[4][4]) {
    std::cout << "Enter matrix data:" << std::endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void PrintMatrix (int (&matrix)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void ConvertToDiagonalMatrix (int (&matrix)[4][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < i; j++) {
            matrix[i][j] = 0;
        }
    }
}

int main() {
    int matrix [4][4];

    InputData( matrix);
    PrintMatrix( matrix);

    ConvertToDiagonalMatrix( matrix);
    PrintMatrix( matrix);

    return 0;
}

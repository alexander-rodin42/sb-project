#include <iostream>

void InputData (char name, int (&matrix)[4][4]) {
    std::cout << "Enter matrix " << name << std::endl;

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

std::string CompareMatrices (int (&firstMatrix)[4][4], int (&secondMatrix)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (firstMatrix[i][j] != secondMatrix[i][j]) {
                return "Matrices are not equal.";
            }
        }
    }
    return "Matrices are equal.";
}

int main() {
    int matrixA [4][4];
    int matrixB [4][4];

    InputData( 'A', matrixA);
    InputData( 'B', matrixB);

    PrintMatrix( matrixA);
    PrintMatrix( matrixB);

    std::cout << CompareMatrices( matrixA, matrixB) << std::endl;

    return 0;
}

#include <iostream>

void InputMatrixData (char name, float (&matrix)[4][4]) {
    std::cout << "Enter matrix " << name << std::endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

void InputVectorData (char name, float (&vector)[4]) {
    std::cout << "Enter vector " << name << std::endl;

    for (int i = 0; i < 4; i++) {
            std::cin >> vector[i];
    }
}

void PrintMatrix (float (&matrix)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintVector (float (&vector)[4]) {
    for (int i = 0; i < 4; i++) {
        std::cout << vector[i] << std::endl;
    }
    std::cout << std::endl;
}

void MatrixVectorMultiplication (float (&vectorResult)[4], float (&vector)[4], float (&matrix)[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            vectorResult[i] += vector[i] * matrix[i][j];
        }
    }
}

int main() {
    float vectorV [4];
    float vectorR [4] = {0.0, 0.0, 0.0, 0.0};
    float matrixM [4][4];

    InputVectorData('V', vectorV);
    InputMatrixData( 'M', matrixM);

    PrintVector(vectorV);
    std::cout << "*" << std::endl << std::endl;
    PrintMatrix( matrixM);

    std::cout << "=" << std::endl << std::endl;
    MatrixVectorMultiplication( vectorR, vectorV, matrixM);
    PrintVector(vectorR);

    return 0;
}

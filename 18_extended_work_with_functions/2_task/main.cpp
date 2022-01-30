#include <iostream>

int GetNumberOfWays (int segmentSize) {
    if (segmentSize < 0) {
        segmentSize *= -segmentSize;
    }

    int result = 0;

    if (segmentSize == 0) {
        return 1;
    }
    if (segmentSize >= 1) {
        result += GetNumberOfWays(segmentSize - 1);
    }
    if (segmentSize >= 2) {
        result += GetNumberOfWays(segmentSize - 2);
    }
    if (segmentSize >= 3) {
        result += GetNumberOfWays(segmentSize - 3);
    }
    return result;
}

int main() {
    int numberOfSteps;

    std::cout << "Enter the number of steps: ";
    std::cin >> numberOfSteps;

    std::cout << GetNumberOfWays( numberOfSteps);

    return 0;
}

/*
    Задача 2

    Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на 1, 2 или 3 ступеньки вверх. Кролик хочет
допрыгать до n-й ступеньки, но может сделать это большим количеством способов.

    Напишите рекурсивную функцию, которая принимает число n типа int, а возвращает количество способов, которыми кролик
может доскакать до n-й ступеньки.
 */

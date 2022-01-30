#include <iostream>

int GetNumberOfWays (int segmentSize, int step = 3) {
    int result = 0;

    if (segmentSize < 0) {
        segmentSize *= -segmentSize;
    }
    for (int i = 1; i <= step; i++) {
        if (segmentSize == 0) {
            return 1;
        }
        if (segmentSize >= i) {
            result += GetNumberOfWays(segmentSize - i, step);
        }
    }
    return result;
}

int main() {

    int numberOfSteps;
    int maxJumpLength;

    std::cout << "Enter the number of steps: ";
    std::cin >> numberOfSteps;
    std::cout << "Enter the maximum jump length: ";
    std::cin >> maxJumpLength;

    std::cout << GetNumberOfWays( numberOfSteps, maxJumpLength);

    return 0;
}

/*
    Задача 3

    Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на одну или более ступенек вверх, но не далее
чем на k. Кролик хочет допрыгать до n-й ступеньки, но может сделать это большим количеством способов.

    Напишите рекурсивную функцию, которая принимает число n типа int и число k — максимальную длину прыжка, а возвращает
количество способов, которым кролик может доскакать до n-й ступеньки. Если максимальная длина прыжка не задана — считать
её равной трём.
 */
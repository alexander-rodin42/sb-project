#include <iostream>

void GetEvenDigits (long long number, int& result) {
    if (number % 2 == 0) {
        result++;
    }
    if (number > 10) {
        GetEvenDigits( number / 10, result);
    }
}

int main() {

    long long bigNumber;
    int ans = 0;

    std::cout << "Enter a large number: ";
    std::cin >> bigNumber;

    GetEvenDigits( bigNumber, ans);
    std::cout << ans;

    return 0;
}

/*
    Задача 4

    Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, а возвращает void.
После завершения работы функции в переменной ans должно оказаться количество чётных цифр в записи числа n.
*/

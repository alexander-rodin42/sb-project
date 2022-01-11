#include <iostream>
#include <sstream>

int main() {
    int integer,
        fraction;

    std::cout << "Enter the whole part of the number: ";
    std::cin >> integer;
    std::cout << "Enter the fractional part of the number: ";
    std::cin >> fraction;

    std::stringstream number;
    number << integer << "." << fraction;

    double result = 0.0;
    number >> result;

    std::cout << result << std::endl;
    return 0;
}

/*
    Сшиватель дробных чисел

    Надо написать небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь надо
составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки.
*/

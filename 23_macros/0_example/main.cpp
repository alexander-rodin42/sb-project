#include <iostream>

#define TITLE "Hello"

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

#define MIN(a, b) ((a < (b)) ? (a) : (b))
#define MAX(a, b) ((a > (b)) ? (a) : (b))

#define COMBINE(first, second) first ## _ ## second

int main() {
    std::cout << "(1)-------------------------------" << std::endl;

    char* complexTitle = TITLE " world!";   //ISO C++11 does not allow conversion from string literal to 'char *'
    std::cout << TITLE << std::endl;
    std::cout << complexTitle << std::endl;

    std::cout << "(2)-------------------------------" << std::endl;

    int command;
    std::cin >> command;
    if (command == UP) {
        std::cout << "UP!" << std::endl;
    }
    else if (command == DOWN) {
        std::cout << "DOWN!" << std::endl;
    }
    else if (command == LEFT) {
        std::cout << "LEFT!" << std::endl;
    }
    else if (command == RIGHT) {
        std::cout << "RIGHT!" << std::endl;
    }

    std::cout << "(3)-------------------------------" << std::endl;

    std::cout << MIN(10, 8) << std::endl;
    std::cout << MAX(10, 8) << std::endl;
    std::cout << MAX(30, MIN(40, 10)) << std::endl;
    std::cout << MAX(30.5, MIN(40.23, 10.123)) << std::endl;

    std::cout << "(4)-------------------------------" << std::endl;

    int serial_number = 20;
    std::cout << serial_number << std::endl;
    COMBINE(serial, number) = 10;
    std::cout << COMBINE(serial, number) << std::endl;

    std::cout << "(5)-------------------------------" << std::endl;

#if 0
    std::string message = "Hello world!";
    std::cout << message << std::endl;
#endif

    return 0;
}

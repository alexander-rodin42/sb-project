#include <iostream>
#include <string>

bool CheckNumber (const std::string& number) {
    int dot = 0;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '.') {
            dot++;
        } else if (number[i] == '-' && i == 0) {

        } else if (number[i] < '0' || number[i] > '9' || dot > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string expression,
                temp,
                action;

    double firstOperand,
           secondOperand;

    std::cout << "Enter an expression in the format \"<number-1><action><number-2>\": ";
    std::cin >> expression;

    for (int i = 0; i < expression.length(); i++) {
        if (i != 0 && action.length() == 0 && (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')) {
            action = expression[i];

            if (!CheckNumber( temp)) {
                break;
            } else {
                firstOperand = std::stod( temp);
            }
            temp = "";
        } else {
            temp += expression[i];
        }
    }

    if (!CheckNumber( temp)) {
        std::cout << "Invalid input." << std::endl;
    } else {
        secondOperand = std::stod( temp);
        //std::cout << firstOperand << action << secondOperand << std::endl;

        if (action == "+") {
            std::cout << firstOperand + secondOperand << std::endl;
        } else if (action == "-") {
            std::cout << firstOperand - secondOperand << std::endl;
        } else if (action == "*") {
            std::cout << firstOperand * secondOperand << std::endl;
        } else {
            std::cout << firstOperand / secondOperand << std::endl;
        }
    }
    return 0;
}

/*
    Калькулятор

    Требуется создать небольшую программу для вычисления простых действий с числами. При запуске программа ожидает
пользовательского ввода во временную переменную строку. После ввода строки, она распарсивается на отдельные члены.
Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). Оба числа - это значения с плавающей точкой,
повышенной точности (double). Действие может быть одним из: +, -, /, *. Результат действия выводится в стандартный вывод
cout.

*/
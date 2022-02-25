#include <iostream>
#include <string>
#include <cmath>

struct Vector {
    double x{};
    double y{};

    void SetParameters (const std::string& vectorName) {
        std::cout << "Enter the x coordinate for the \"" << vectorName << "\" vector: ";
        std::cin >> this->x;
        std::cout << "Enter the y coordinate for the \"" << vectorName << "\" vector: ";
        std::cin >> this->y;
    }
};

bool CheckCommand (const std::string (&possibleCommands)[5], const std::string& inputCommand) {
    for (auto & command : possibleCommands) {
        if (inputCommand == command) {
            return true;
        }
    }
    return false;
}

void PrintCommands (const std::string (&possibleCommands)[5]) {
    std::cout << "Possible commands: ";
    for (auto &command: possibleCommands) {
        std::cout << command << ", ";
    }
    std::cout << std::endl;
}

void OperationAdd () {
    Vector a, b;

    a.SetParameters("a");
    b.SetParameters("b");

    std::cout << "Sum of vectors: {" << a.x + b.x << "; " << a.y + b.y << "}" << std::endl;
}

void OperationSubtract () {
    Vector a, b;

    a.SetParameters("a");
    b.SetParameters("b");

    std::cout << "Difference of vectors: {" << a.x - b.x << "; " << a.y - b.y << "}" << std::endl;
}

void OperationScale () {
    Vector a;
    double multiplier;

    a.SetParameters("a");
    std::cout << "Enter multiplier: ";
    std::cin >> multiplier;

    a.x *= multiplier;
    a.y *= multiplier;
    std::cout << "Vector a multiplied by " << multiplier << ": {" << a.x << "; " << a.y << "}" << std::endl;
}

void OperationLength () {
    Vector a;

    a.SetParameters("a");

    std::cout << "The length of the vector a: " << sqrt( pow(a.x, 2) + pow(a.y, 2)) << std::endl;
}

void OperationNormalize () {
    Vector a;

    a.SetParameters("a");
    double length = sqrt( pow(a.x, 2) + pow(a.y, 2));

    if (length != 0) {
        std::cout << "Normalized vector a: {" << a.x / length << "; " << a.y / length << "}" << std::endl;
    }
    else {
        std::cout << "The vector a is zero." << std::endl;
    }
}

void ExecuteAnOperation (const std::string& userCommand) {
    if (userCommand == "add") {
        OperationAdd();
    }
    else if (userCommand == "subtract") {
        OperationSubtract();
    }
    else if (userCommand == "scale") {
        OperationScale();
    }
    else if (userCommand == "length") {
        OperationLength();
    }
    else if (userCommand == "normalize"){
        OperationNormalize ();
    }
    else {
        std::cout << "Operation not found." << std::endl;
    }
}

int main() {
    std::string userCommand;
    const std::string possibleCommands[5] = {"add", "subtract", "scale", "length", "normalize"};

    PrintCommands( possibleCommands);
    do {
        std::cout << "Enter the command to perform the required operation: ";
        std::cin >> userCommand;
    } while ( !CheckCommand( possibleCommands, userCommand));

    ExecuteAnOperation( userCommand);

    return 0;
}

/*
Задание 3. Реализация математического вектора

    Реализуйте структуру двумерного математического вектора и основные операции над ним. Обе координаты вектора (x и y)
должны быть вещественными числами.

    Вначале программы пользователь вводит команду, которая соответствует требуемой операции. Далее, в зависимости от
операции, пользователь вводит её аргументы. Это могут быть как вектора, так и обычные, скалярные значения. В результате
в стандартный вывод помещается результат. Это тоже может быть или вектор, или скаляр.

Реализуйте следующие операции в виде отдельных функций:

Сложение двух векторов — команда add.
Вычитание двух векторов — команда subtract.
Умножение вектора на скаляр — команда scale.
Нахождение длины вектора — команда length.
Нормализация вектора — команда normalize.
*/

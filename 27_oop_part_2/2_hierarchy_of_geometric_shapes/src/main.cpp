#include <iostream>
#include <cassert>

#include "Circle.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Rectangle.h"

void InputCommand (std::string& command) {
    do {
        std::cout << "> Enter the command: ";
        std::cin >> command;
    }
    while (!(command == "circle"
          || command == "triangle"
          || command == "square"
          || command == "rectangle"
          || command == "exit"));
}

int main() {
    std::string command;

    std::cout << "Available commands: circle, triangle, square, rectangle, exit." << std::endl;

    do {
        InputCommand(command);

        if (command == "circle") {
            auto* circle = new Circle();
            circle->setParameters();

            std::cout << "The area of a circle is: " << circle->getArea() << std::endl;
            circle->fitInRectangle();
            delete circle;
        }
        else if (command == "triangle") {
            auto* triangle = new EquilateralTriangle();
            triangle->setParameters();

            std::cout << "The area of a equilateral triangle is: " << triangle->getArea() << std::endl;
            triangle->fitInRectangle();
            delete triangle;
        }
        else if (command == "square") {
            auto* square = new Square();
            square->setParameters();

            std::cout << "The area of a square is: " << square->getArea() << std::endl;
            square->fitInRectangle();
            delete square;
        }
        else if (command == "rectangle") {
            auto* rectangle = new Rectangle();
            rectangle->setParameters();

            std::cout << "The area of a rectangle is: " << rectangle->getArea() << std::endl;
            rectangle->fitInRectangle();
            delete rectangle;
        }
    }
    while (command != "exit");

    return 0;
}

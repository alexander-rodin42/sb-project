#include <iostream>
#include <cassert>

#include "Circle.h"
#include "EquilateralTriangle.h"
#include "Square.h"
#include "Rectangle.h"

void InputCommand (std::string& command) {
    do {
        std::cout << "> Enter command: ";
        std::cin >> command;
    }
    while (!(command == "circle"
          || command == "triangle"
          || command == "square"
          || command == "rectangle"
          || command == "exit"));
}

void  BuildCircle() {
    auto* circle = new Circle();
    circle->setParameters();

    std::cout << "The area of a circle is: " << circle->getArea() << std::endl;
    auto* temp = circle->fitInRectangle();
    temp->print();

    delete temp;
    delete circle;
}

void BuildTriangle() {
    auto* triangle = new EquilateralTriangle();
    triangle->setParameters();

    std::cout << "The area of a equilateral triangle is: " << triangle->getArea() << std::endl;
    auto* temp = triangle->fitInRectangle();
    temp->print();

    delete temp;
    delete triangle;
}

void BuildSquare() {
    auto* square = new Square();
    square->setParameters();

    std::cout << "The area of a square is: " << square->getArea() << std::endl;
    auto* temp = square->fitInRectangle();
    temp->print();

    delete temp;
    delete square;
}

void BuildRectangle() {
    auto* rectangle = new Rectangle();
    rectangle->setParameters();

    std::cout << "The area of a rectangle is: " << rectangle->getArea() << std::endl;
    auto* temp = rectangle->fitInRectangle();
    temp->print();

    delete temp;
    delete rectangle;
}

int main() {
    std::string command;

    std::cout << "Available commands: circle, triangle, square, rectangle, exit." << std::endl;

    do {
        InputCommand(command);

        if (command == "circle") {
            BuildCircle();
        }
        else if (command == "triangle") {
            BuildTriangle();
        }
        else if (command == "square") {
            BuildSquare();
        }
        else if (command == "rectangle") {
            BuildRectangle();
        }
    }
    while (command != "exit");

    return 0;
}

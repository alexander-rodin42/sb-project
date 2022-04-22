#include <iostream>

#include "GeometricFigure.h"

void GeometricFigure::setCenterCoordinates() {
    std::cout << "Enter X coordinate: ";
    std::cin >> center.x;
    std::cout << "Enter Y coordinate: ";
    std::cin >> center.y;
}

void GeometricFigure::setColor() {
    std::string input;
    std::cout << "Available colors: red, blue, green." << std::endl;
    do {
        std::cout << "Enter shape color: ";
        std::cin >> input;
    } while (!(input == "red"
            || input == "blue"
            || input == "green"));

    if (input == "red") {
        color = RED;
    }
    else if (input == "blue") {
        color = BLUE;
    }
    else if (input == "green") {
        color = GREEN;
    }
}

Point GeometricFigure::getCenter() {
    return center;
}

void GeometricFigure::setCenter(const Point& inCenter) {
    center = inCenter;
}


void Point::print() const {
    std::cout << x << ", " << y;
}

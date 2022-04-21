#include <iostream>
#include <cmath>

#include "Rectangle.h"

void Rectangle::setEdgeLength() {
    do {
        std::cout << "Enter the length of the first edge of the rectangle: ";
        std::cin >> firstEdgeLength;
    } while (firstEdgeLength < 0);

    do {
        std::cout << "Enter the length of the second edge of the rectangle: ";
        std::cin >> secondEdgeLength;
    } while (secondEdgeLength < 0);
}

double Rectangle::getArea() const {
    return firstEdgeLength * secondEdgeLength;
}

void Rectangle::fitInRectangle() const {
    std::cout << "A rectangle can be described by a rectangle with sides: " << firstEdgeLength
              << " end " << secondEdgeLength << std::endl;
}

void Rectangle::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setEdgeLength();
}

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

Rectangle *Rectangle::fitInRectangle() {
    auto* result = new Rectangle;

    result->setCenter(this->getCenter());
    result->setFirstEdgeLength(firstEdgeLength);
    result->setSecondEdgeLength(secondEdgeLength);

    return result;
}

void Rectangle::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setEdgeLength();
}

void Rectangle::setFirstEdgeLength(const double& value) {
    firstEdgeLength = value;
}

void Rectangle::setSecondEdgeLength(const double& value) {
    secondEdgeLength = value;
}

void Rectangle::print() {
    std::cout << "Rectangle options." << std::endl;
    std::cout << "Center coordinates ";
    getCenter().print();

    std::cout << ", first edge length: " << firstEdgeLength << ", second edge length: " << secondEdgeLength << std::endl;
}




#include <iostream>
#include <cmath>

#include "Square.h"

void Square::setEdgeLength() {
    do {
        std::cout << "Enter the length of the edge of the square: ";
        std::cin >> edgeLength;
    } while (edgeLength < 0);
}

double Square::getArea() const {
    return edgeLength * edgeLength;
}

void Square::fitInRectangle() const {
    std::cout << "A square can be described by a rectangle with a side: " << edgeLength << std::endl;
}

void Square::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setEdgeLength();
}


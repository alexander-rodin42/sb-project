#include <iostream>
#include <cmath>

#include "EquilateralTriangle.h"

void EquilateralTriangle::setEdgeLength() {
    do {
        std::cout << "Enter the length of the edge of the triangle: ";
        std::cin >> edgeLength;
    } while (edgeLength < 0);
}

double EquilateralTriangle::getArea() const {
    return edgeLength * edgeLength * sqrt(3) / 4;
}

void EquilateralTriangle::fitInRectangle() const {
    std::cout << "A triangle can be described by a rectangle with sides: " << edgeLength
              << " end " << sqrt(pow(edgeLength, 2) - pow(edgeLength / 2, 2)) << std::endl;
}

void EquilateralTriangle::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setEdgeLength();
}


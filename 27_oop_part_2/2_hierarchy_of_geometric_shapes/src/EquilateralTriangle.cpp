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

Rectangle* EquilateralTriangle::fitInRectangle() {
    auto* result = new Rectangle;

    result->setCenter(this->getCenter());
    result->setFirstEdgeLength(edgeLength);
    result->setSecondEdgeLength(sqrt(pow(edgeLength, 2) - pow(edgeLength / 2, 2)));

    return result;
}

void EquilateralTriangle::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setEdgeLength();
}


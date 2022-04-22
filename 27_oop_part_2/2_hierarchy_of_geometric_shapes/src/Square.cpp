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

Rectangle *Square::fitInRectangle() {
    auto* result = new Rectangle;

    result->setCenter(this->getCenter());
    result->setFirstEdgeLength(edgeLength);
    result->setSecondEdgeLength(edgeLength);

    return result;
}

void Square::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setEdgeLength();
}




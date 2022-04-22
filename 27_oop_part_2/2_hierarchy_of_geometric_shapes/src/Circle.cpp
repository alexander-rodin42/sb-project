#include <iostream>
#include <cmath>

#include "Circle.h"

void Circle::setRadius() {
    do {
        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;
    } while (radius < 0);
}

double Circle::getArea() const {
    return atan(1) * 4 * pow(radius, 2);
}

Rectangle* Circle::fitInRectangle() {
    auto* result = new Rectangle;

    result->setCenter(this->getCenter());
    result->setFirstEdgeLength(radius);
    result->setSecondEdgeLength(radius);

    return result;
}

void Circle::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setRadius();
}

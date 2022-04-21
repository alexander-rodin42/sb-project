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

void Circle::fitInRectangle() const {
    std::cout << "A circle can be described by a rectangle with a side: " << radius + radius << std::endl;
}

void Circle::setParameters() {
    this->setColor();
    this->setCenterCoordinates();
    this->setRadius();
}

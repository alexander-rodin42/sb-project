#include <iostream>
#include "point.h"

void Point::SetCoordinates() {
    std::cout << "Enter x coordinate: ";
    std::cin >> this->x;
    std::cout << "Enter y coordinate: ";
    std::cin >> this->y;
}

bool Point::Equal (const Point& that) {
    return this->x == that.x && this->y == that.y;
}
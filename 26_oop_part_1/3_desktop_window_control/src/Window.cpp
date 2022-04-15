#include <iostream>

#include "Window.h"
#include "ScreenResolution.h"

void Window::setCoordinate() {
    do {
        std::cout << "Enter x coordinate: ";
        std::cin >> x;
    }
    while (!(x >= 0 && x < WIDTH));

    do {
        std::cout << "Enter y coordinate: ";
        std::cin >> y;
    }
    while (!(y >= 0 && y < HEIGHT));

    x--;
    y--;
}

void Window::move(const int& xShift, const int& yShift) {
    if (x + xShift < 0) {
        x = 0;
    }
    else if (x + xShift > WIDTH) {
        x = WIDTH;
    }
    else {
        x += xShift;
    }

    if (y + yShift < 0) {
        y = 0;
    }
    else if (y + yShift > HEIGHT) {
        y = HEIGHT;
    }
    else {
        y += yShift;
    }

}

void Window::resize() {
    do {
        std::cout << "Enter window height: ";
        std::cin >> height;
    }
    while (height <= 0);

    do {
        std::cout << "Enter window width: ";
        std::cin >> width;
    }
    while (width <= 0);
}

int Window::getX() const {
    return x;
}

int Window::getY() const {
    return y;
}

int Window::getHeight() const {
    return height;
}

int Window::getWidth() const {
    return width;
}








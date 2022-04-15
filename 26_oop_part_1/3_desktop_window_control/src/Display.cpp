#include <iostream>

#include "Display.h"

void Display::clean() {
    for (auto & i : screen) {
        for (auto & j : i) {
            j = '0';
        }
    }
}

void Display::print() {
    std::cout << '+';
    for (int i = 0; i < WIDTH; ++i) {
        std::cout << '-';
    }
    std::cout << '+' << std::endl;

    for (auto & i : screen) {
        std::cout << '|';
        for (auto & j : i) {
            std::cout << j;
        }
        std::cout << '|' << std::endl;
    }

    std::cout << '+';
    for (int i = 0; i < WIDTH; ++i) {
        std::cout << '-';
    }
    std::cout << '+' << std::endl;
}

void Display::paintPixel(const int& height, const int& width) {
    if (width >= 0 && width < WIDTH && height >= 0 && height < HEIGHT) {
        screen[height][width] = '1';
    }
}

void Display::paintWindow(const Window& window) {
    int xBegin = 0;
    int yBegin = 0;
    int xEnd = WIDTH;
    int yEnd = HEIGHT;

    if (window.getX() >= 0)
        xBegin = window.getX();

    if (window.getY() >= 0)
        yBegin = window.getY();

    if (window.getX() + window.getWidth() < WIDTH)
        xEnd = window.getX() + window.getWidth();

    if (window.getY() + window.getHeight() < HEIGHT)
        yEnd = window.getY() + window.getHeight();

    for (int i = yBegin; i < yEnd; ++i) {
        for (int j = xBegin; j < xEnd; ++j) {
            this->paintPixel(i,j);
        }
    }

}
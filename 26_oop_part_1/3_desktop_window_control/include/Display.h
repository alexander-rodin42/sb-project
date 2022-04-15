#pragma once

#include "ScreenResolution.h"
#include "Window.h"

class Display {
public:
    void clean();
    void print();
    void paintPixel(const int& height, const int& width);
    void paintWindow(const Window& window);
private:
    char screen[HEIGHT][WIDTH]{};
};


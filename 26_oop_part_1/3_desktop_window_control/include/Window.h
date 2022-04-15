#pragma once

class Window {
public:
    void setCoordinate();
    void move(const int& xShift, const int& yShift);
    void resize();
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;
private:
    int x = 0;
    int y = 0;
    int height = 0;
    int width = 0;
};


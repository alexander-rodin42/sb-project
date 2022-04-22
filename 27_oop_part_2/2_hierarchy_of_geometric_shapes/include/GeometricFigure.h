#pragma once

enum color {
    NONE  = 0,
    RED   = 1,
    BLUE  = 2,
    GREEN = 3
};

struct Point {
    double x = 0;
    double y = 0;

    void print() const;
};

class GeometricFigure {
public:
    void setCenterCoordinates();
    void setColor();
    Point getCenter();
    void setCenter(const Point& inCenter);

private:
    Point center{};
    color color = NONE;
};


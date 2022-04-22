#pragma once

#include "GeometricFigure.h"
#include "Rectangle.h"

class Circle : public GeometricFigure {
public:
    void setRadius();
    double getArea() const;
    Rectangle* fitInRectangle();
    void setParameters();
private:
    double radius = 0;
};


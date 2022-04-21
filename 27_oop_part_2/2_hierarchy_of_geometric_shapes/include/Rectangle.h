#pragma once

#include "GeometricFigure.h"

class Rectangle : GeometricFigure{
public:
    void setEdgeLength();
    double getArea() const;
    void fitInRectangle() const;
    void setParameters();
private:
    double firstEdgeLength = 0;
    double secondEdgeLength = 0;
};

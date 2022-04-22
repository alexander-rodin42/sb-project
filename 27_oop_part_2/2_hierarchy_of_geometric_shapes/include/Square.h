#pragma once

#include "GeometricFigure.h"
#include "Rectangle.h"

class Square : public GeometricFigure {
public:
    void setEdgeLength();
    double getArea() const;
    Rectangle* fitInRectangle();
    void setParameters();
private:
    double edgeLength = 0;
};
#pragma once

#include "GeometricFigure.h"
#include "Rectangle.h"

class EquilateralTriangle : public GeometricFigure {
public:
    void setEdgeLength();
    double getArea() const;
    Rectangle* fitInRectangle();
    void setParameters();

private:
    double edgeLength = 0;
};

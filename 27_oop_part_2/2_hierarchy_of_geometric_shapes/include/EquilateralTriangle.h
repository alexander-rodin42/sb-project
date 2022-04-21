#pragma once

#include "GeometricFigure.h"

class EquilateralTriangle : public GeometricFigure {
public:
    void setEdgeLength();
    double getArea() const;
    void fitInRectangle() const;
    void setParameters();
private:
    double edgeLength = 0;
};

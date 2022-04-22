#pragma once

#include "GeometricFigure.h"

class Rectangle : public GeometricFigure{
public:
    void setEdgeLength();
    double getArea() const;
    Rectangle* fitInRectangle();
    void setParameters();
    void setFirstEdgeLength(const double& value);
    void setSecondEdgeLength(const double& value);
    void print();

private:
    double firstEdgeLength = 0;
    double secondEdgeLength = 0;
};

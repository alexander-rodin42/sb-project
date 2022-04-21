#pragma one

#include "GeometricFigure.h"

class Square : GeometricFigure {
public:
    void setEdgeLength();
    double getArea() const;
    void fitInRectangle() const;
    void setParameters();
private:
    double edgeLength = 0;
};
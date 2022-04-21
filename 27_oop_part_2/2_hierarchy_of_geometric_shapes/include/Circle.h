#pragma one

#include "GeometricFigure.h"

class Circle : public GeometricFigure {
public:
    void setRadius();
    double getArea() const;
    void fitInRectangle() const;
    void setParameters();
private:
    double radius = 0;
};


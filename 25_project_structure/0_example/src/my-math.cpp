#include <cmath>
#include "my-math.h"

double pi() {
    return atan(1.0) * 4.0;
}

double circumference(const double& radius) {
    return 2 * pi() * radius;
}
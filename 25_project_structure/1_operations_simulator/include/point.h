#pragma once

struct Point {
    double x{};
    double y{};

    void SetCoordinates ();

    bool Equal(const Point &that);
};


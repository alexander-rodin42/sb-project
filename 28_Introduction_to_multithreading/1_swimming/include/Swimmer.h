#pragma once

#include <iostream>

class Swimmer {
public:
    Swimmer();
    std::string getName ();
    double getSpeed() const;

private:
    std::string name = "no name";
    double speed = 0;
};


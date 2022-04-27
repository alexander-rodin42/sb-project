#pragma once

#include <iostream>

class Swimmer {
public:
    Swimmer();
    std::string getName ();
    double getSpeed() const;
    bool checkFinish() const;
    void finish();

private:
    std::string name = "no name";
    double speed = 0;
    bool finished = false;
};


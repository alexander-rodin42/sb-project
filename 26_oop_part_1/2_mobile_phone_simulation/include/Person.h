#pragma once

#include <iostream>

#include "Verification.h"

class Person {
public:
    std::string getName ();
    std::string getPhoneNumber();
    void setParameters ();

private:
    std::string name;
    std::string phoneNumber{};

    void setName ();
    void setPhoneNumber ();
};


#pragma once

class Toy {
public:
    Toy(const std::string& inName);
    Toy();

    std::string getName();
private:
    std::string name;
};


#include "Swimmer.h"
#include "Verification.h"

Swimmer::Swimmer() {
    do {
        std::cout << "Enter name: ";
        std::cin >> name;
    }
    while (!CheckName(name));
    ConvertNameToFormat(name);

    do {
        std::cout << "Enter the swimmer's turn in meters per second: ";
        std::cin >> speed;
    }
    while (!(speed > 0 && speed < 100));
}

std::string Swimmer::getName() {
    return name;
}

double Swimmer::getSpeed() const {
    return speed;
}

bool Swimmer::checkFinish() const {
    return finished;
}

void Swimmer::finish() {
    finished = true;
}


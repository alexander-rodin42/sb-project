#include <iostream>
#include "incision.h"
#include "point.h"

void Incision::MakeCut() {
    do {
        std::cout << "Start and end coordinates must not match." << std::endl;
        std::cout << "Enter the coordinates of the beginning of the cut." << std::endl;
        this->begin.SetCoordinates();
        std::cout << "Enter the coordinates of the end of the cut." << std::endl;
        this->end.SetCoordinates();
    }
    while (this->begin.Equal(this->end));
}

void Incision::SewIncision() {
    Point inputBegin;
    Point inputEnd;

    do {
        std::cout << "Enter the coordinates of the beginning of the cut." << std::endl;
        inputBegin.SetCoordinates();
        std::cout << "Enter the coordinates of the end of the cut." << std::endl;
        inputEnd.SetCoordinates();
    }
    while ( !(this->begin.Equal(inputBegin) && this->end.Equal(inputEnd) ||
              this->begin.Equal(inputEnd) && this->end.Equal(inputBegin)));
}

void Scalpel(Incision& incision) {
    incision.MakeCut();
    std::cout << "A cut is made from point (" << incision.begin.x << ":" << incision.begin.y << ") to point ("
              << incision.end.x << ":" << incision.end.y <<  ")." << std::endl;
}

void Hemostat () {
    Point point;
    point.SetCoordinates();
    std::cout << "The clamp is installed at the point ("<< point.x << ":" << point.y <<")." << std::endl;
}

void Tweezers() {
    Point point;
    point.SetCoordinates();
    std::cout << "The tweezer is applied to the point ("<< point.x << ":" << point.y <<")." << std::endl;
}

void Suture(Incision& incision) {
    incision.SewIncision();
    std::cout << "The cut from point (" << incision.begin.x << ":" << incision.begin.y << ") to point ("
              << incision.end.x << ":" << incision.end.y <<  ") is sewn." << std::endl;
}

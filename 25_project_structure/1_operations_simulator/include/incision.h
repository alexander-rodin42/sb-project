#pragma once
#include "point.h"

struct Incision {
    Point begin{};
    Point end{};

    void MakeCut ();
    void SewIncision ();
};

void Scalpel(Incision& incision);
void Hemostat();
void Tweezers();
void Suture(Incision& incision);
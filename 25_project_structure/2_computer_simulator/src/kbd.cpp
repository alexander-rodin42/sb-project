#include <iostream>
#include <string>
#include "kbd.h"
#include "ram.h"
#include "gpu.h"

void input(Buffer& buffer) {
    for (int i = 0; i < 8; ++i) {
        display(std::to_string(i + 1) + " Enter number: ");
        int value;
        std::cin >> value;
        buffer.write(i, value);
    }

    buffer.recordingCompleted(true);
}
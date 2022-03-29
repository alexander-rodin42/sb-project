#include "cpu.h"
#include "ram.h"
#include "gpu.h"

void compute(Buffer& buffer) {
    int cache = 0;
    buffer.read(cache);

    if (buffer.empty()) {
        display("RAM is empty.", true);
    }
    else {
        for (int i = 0; i < 8; ++i) {
            cache += buffer.read(i);
        }

        display("The sum of the numbers is: ");
        display(cache);
    }
}
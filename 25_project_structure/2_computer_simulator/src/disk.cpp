#include <iostream>
#include <fstream>
#include <string>
#include "disk.h"
#include "ram.h"
#include "gpu.h"

void save(Buffer& buffer) {
    if (buffer.empty()) {
        display("RAM is empty.", true);
    }
    else {
        std::ofstream outFile;
        outFile.open("data.txt");

        for (int i = 0; i < 8; ++i) {
            outFile << std::to_string(buffer.read(i)) << std::endl;
        }
        outFile.close();
        display("File \"data.txt\" saved successfully.", true);
    }
}

void load(Buffer& buffer) {
    std::ifstream inFile;
    inFile.open("data.txt");

    if (!inFile.is_open()) {
        display("File \"data.txt\" not found.", true);
    }
    else {
        for (int i = 0; i < 8; ++i) {
            int value = 0;
            if (!inFile.eof()) {
                inFile >> value;
                buffer.write(i, value);
            }
            else {
                buffer.write(i, value);
            }
        }
        buffer.recordingCompleted(true);
        inFile.close();
        display("The file \"data.txt\" was successfully uploaded.", true);
    }

}
#include "ram.h"

void Buffer::write(const int& index, const int& value) {
    if (index >= 0 && index < 8) {
        this->buffer[index] = value;
    }
}

int Buffer::read(const int& index) {
    return index >= 0 && index < 8 ? this->buffer[index] : 0;
}

bool Buffer::empty() const {
    return isEmpty;
}

void Buffer::recordingCompleted(const bool &value) {
    isEmpty = !value;
}

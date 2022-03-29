#pragma once

struct Buffer {
public:
    void write(const int& index, const int& value);
    int read(const int& index);
    bool empty() const;
    void recordingCompleted (const bool& value);

private:
    int buffer[8];
    bool isEmpty = true;
};
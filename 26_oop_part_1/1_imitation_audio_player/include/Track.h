#pragma once

#include <iostream>
#include <ctime>

class Track {
public:
    Track();
    Track(std::string name, const std::time_t& creationDate, const std::time_t& recordingDuration);
    void showInfo ();

private:
    std::string name{};
    std::time_t creationDate{};
    std::time_t recordingDuration{};
};
#pragma once

#include <map>

#include "Track.h"

enum commands {
    PLAY,
    PAUSE,
    STOP
};

class AudioPlayer {
public:
    bool readMemory();
    void print();

    void play();
    void pause();
    void stop();
    void next();

private:
    int status = STOP;
    std::map<std::string, Track> memory{};
    std::map<std::string, Track>::iterator currentTrack = memory.begin();
};
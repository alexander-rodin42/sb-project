#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

#include "AudioPlayer.h"

bool AudioPlayer::readMemory() {
    std::ifstream inFile;
    inFile.open ("CompactDisk.txt");

    if (!inFile.is_open()) {
        std::cout << "File not found." << std::endl;
        return false;
    }

    while (!inFile.eof()) {
        std::string name;
        std::time_t creationDate = 0;
        std::time_t recordingDuration = 0;
        struct tm date{};
        localtime_s(&date, &creationDate);
        struct tm duration{};
        localtime_s(&duration, &recordingDuration);

        inFile >> name >> std::get_time(&date, "%Y/%m/%d") >> std::get_time(&duration, "%M:%S");

        creationDate = mktime(&date);
        recordingDuration = mktime(&duration);
        Track temp = {name, creationDate, recordingDuration};

        memory[name] = temp;
    }
    return true;
}

void AudioPlayer::print() {
    for (auto i : memory) {
        i.second.showInfo();
    }
}

void AudioPlayer::play() {
    if (status == STOP) {
        std::string trackName;
        std::cout << "Enter track name: ";
        std::cin >> trackName;

        if (memory.find(trackName) != memory.end()) {
            status = PLAY;
            currentTrack = memory.find(trackName);
            std::cout << "(>) Play: ";
            currentTrack->second.showInfo();
        }
        else {
            std::cout << "Track not found." << std::endl;
        }
    }
    else if (status == PAUSE) {
        status = PLAY;
        std::cout << "(>) Play: ";
        currentTrack->second.showInfo();
    }
}

void AudioPlayer::pause() {
    if (status == PLAY) {
        status = PAUSE;
        std::cout << "(||) The track is paused." << std::endl;
    }
}

void AudioPlayer::stop() {
    if (status != STOP) {
        status = STOP;
        std::cout << "([]) The track has stopped playing." << std::endl;
    }
}

void AudioPlayer::next() {
    std::srand(std::time(nullptr));
    int shift = rand() % (memory.size() - 1) + 1;


    while (shift > 0) {
        ++currentTrack;
        --shift;
        if (currentTrack == memory.end()) {
            currentTrack = memory.begin();
        }
    }
    std::cout << "(>>) Play: ";
    currentTrack->second.showInfo();
}

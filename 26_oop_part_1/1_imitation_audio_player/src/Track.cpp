#include <iostream>
#include <ctime>
#include <iomanip>
#include <utility>

#include "Track.h"

Track::Track() = default;

Track::Track(std::string name, const time_t& creationDate, const time_t& recordingDuration)
: name(std::move(name)), creationDate(creationDate), recordingDuration(recordingDuration) {}

void Track::showInfo() {
    struct tm date{};
    localtime_s(&date, &creationDate);

    struct tm duration{};
    localtime_s(&duration, &recordingDuration);

    std::cout << name
              << " (" << std::put_time(&date, "%d %B %Y") << ") "
              << std::put_time(&duration, "%M:%S")
              << std::endl;
}







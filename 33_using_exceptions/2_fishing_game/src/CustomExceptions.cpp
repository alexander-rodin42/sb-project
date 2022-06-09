#include "CustomExceptions.h"

const char *SectorIsEmpty::what() const noexcept {
    return "Sector is empty. Try again.";
}


const char *FishCaughtInTheSector::what() const noexcept {
    return "Congratulations, you caught a fish!";
}

const char *BootCaughtInTheSector::what() const noexcept {
    return "You caught the boot, game over.";
}

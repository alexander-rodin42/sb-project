#pragma once

#include <exception>

class SectorIsEmpty : std::exception {
public:
    const char* what() const noexcept override;
};

class FishCaughtInTheSector : std::exception {
public:
    const char* what() const noexcept override;
};

class BootCaughtInTheSector : std::exception {
public:
    const char* what() const noexcept override;
};


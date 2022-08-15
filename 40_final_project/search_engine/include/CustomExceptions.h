//
// Created by Alexander on 8/2/2022.
//

#pragma once

#include <exception>

class ConfigFileIsMissing : public std::exception {
public:
    const char *what() const noexcept override;
};

class ConfigFileIsEmpty : public std::exception {
public:
    const char *what() const noexcept override;
};

class RequestsFileIsMissing : public std::exception {
public:
    const char *what() const noexcept override;
};

class RequestsFileIsEmpty : public std::exception {
public:
    const char *what() const noexcept override;
};
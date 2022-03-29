#pragma once
#include <string>
#include "ram.h"

void display(const std::string& message, const bool& lineBreak = false);
void display(const int& value);
void display(Buffer& buffer);
#include <algorithm>

#include "Verification.h"

bool CheckName (const std::string& name) {
    return std::all_of(name.begin(), name.end(), [](char i){return i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z';});
}

bool CheckPhoneNumber (const std::string& phoneNumber) {
    if (phoneNumber.length() == 12 && phoneNumber[0] == '+' && phoneNumber[1] == '7') {
        return std::all_of(phoneNumber.begin() + 2, phoneNumber.end(), [](char i){return i >= '0' && i <= '9';});
    }
    else {
        return false;
    }
}

void ConvertNameToFormat(std::string& name) {
    for (int i = 0; i < name.length(); i++){
        if (i == 0 && name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 32;
        }
        else if (i != 0 && name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        }
    }
}
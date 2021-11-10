#include <iostream>
#include <string>

bool CheckNumber (std::string number) {
    if (number.empty() || number.length() > 3 || number.length() > 1 && number[0] == '0') {
        return false;
    } else {
        int currentNumber = 0;
        int numberMultiplier = 1;

        for (char i: number) {
            if (i < '0' || i > '9') {
                return false;
            }
            currentNumber = currentNumber * numberMultiplier + (int)(i - '0');
            numberMultiplier = 10;
        }
        return currentNumber >= 0 && currentNumber < 256;
    }
}

//std::string CheckIpAddress (const std::string& ipAddress) {
//
//    int pointsAmount = 0;
//    std::string currentNumber;
//
//    for (char i : ipAddress) {
//        if (i == '.') {
//            if (!CheckNumber( currentNumber)) {
//                return "No";
//            }
//            pointsAmount++;
//            currentNumber = "";
//        } else {
//            currentNumber += i;
//        }
//    }
//    if (!CheckNumber( currentNumber)) {
//        return "No";
//    }
//    return pointsAmount == 3 ? "Yes" : "No";
//}

std::string CheckIpAddress (std::string ipAddress) {

    int pointsAmount = 0;

    while (ipAddress.find('.') != std::string::npos) {
        if (!CheckNumber( ipAddress.substr(0, ipAddress.find('.')))) {
            return "No";
        }
        pointsAmount++;
        ipAddress = ipAddress.substr(ipAddress.find('.') + 1, ipAddress.length());
    }

    if (!CheckNumber( ipAddress)) {
        return "No";
    }
    return pointsAmount == 3 ? "Yes" : "No";
}

int main() {
    std::string userIpAddress;

    std::cout << "Enter the IP address: ";
    std::cin >> userIpAddress;

    std::cout << CheckIpAddress( userIpAddress) << std::endl;

    return 0;
}

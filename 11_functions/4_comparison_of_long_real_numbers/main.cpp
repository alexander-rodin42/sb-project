#include <iostream>
#include <string>

bool CheckNumber (std::string number) {
    int point = 0;
    bool numberIsCorrect = true;
    bool presenceOfNumbers = false;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '.') point++;
        if (point > 1) {
            numberIsCorrect = false;
            break;
        }
        if (number[i] == '-' && i != 0) {
            numberIsCorrect = false;
            break;
        }

        bool correctCharacters = number[i] == '-' || number[i] == '.' || (number[i] >= '0' && number[i] <= '9');

        if (!correctCharacters) {
            numberIsCorrect = false;
            break;
        }
        if (!presenceOfNumbers && number[i] >= '0' && number[i] <= '9') {
            presenceOfNumbers = true;
        }
    }

    return numberIsCorrect && presenceOfNumbers;
}

std::string GetInteger (std::string number) {
    if (number[0] == '.') {
        return "0";
    } else if (number.find('.') != std::string::npos) {
        number = number.substr(0, number.find('.'));
    }

    bool firstNumberZero = true;
    do {
        if (number.length() > 1 && number[0] == '0') {
            number = number.substr(1, number.length());
        } else {
            firstNumberZero = false;
        }
    } while (firstNumberZero);

    return number;
}

std::string GetFractionalPart (std::string number) {
    if (number.find('.') != std::string::npos) {
        if (number[number.length() - 1] == '.') {
            return "0";
        }
        number = number.substr(number.find('.') + 1, number.length());
    } else {
        return "0";
    }

    bool lastNumberZero = true;
    do {
        if (number.length() > 1 && number[number.length() - 1] == '0') {
            number = number.substr(0, number.length() - 1);
        } else {
            lastNumberZero = false;
        }
    } while (lastNumberZero);
    return number;
}

std::string RemoveMinus (const std::string& number) {
    return number.substr(1, number.length());
}

std::string CompareNumbers (std::string firstNumber, std::string secondNumber) {
    if (firstNumber[0] != '-' && secondNumber[0] == '-') {
        return "More";
    } else if (firstNumber[0] == '-' && secondNumber[0] != '-') {
        return "Less";
    } else {
        bool firstNumberLonger = GetInteger( firstNumber).length() > GetInteger( secondNumber).length();
        bool secondNumberLonger = GetInteger( firstNumber).length() < GetInteger( secondNumber).length();

        if (firstNumber[0] == '-' && secondNumber[0] == '-') {
            firstNumber = RemoveMinus(firstNumber);
            secondNumber = RemoveMinus(secondNumber);

            if (firstNumberLonger) {
                return "Less";
            } else if (secondNumberLonger) {
                return "More";
            } else {
                if (GetInteger( firstNumber) > GetInteger( secondNumber)) {
                    return "Less";
                } else if (GetInteger( firstNumber) < GetInteger( secondNumber)) {
                    return "More";
                } else {
                    if (GetFractionalPart( firstNumber) > GetFractionalPart( secondNumber)) {
                        return "Less";
                    } else if (GetFractionalPart( firstNumber) < GetFractionalPart( secondNumber)) {
                        return "More";
                    } else {
                        return "Equal";
                    }
                }
            }
        } else {
            if (firstNumberLonger) {
                return "More";
            } else if (secondNumberLonger) {
                return "Less";
            } else {
                if (GetInteger( firstNumber) > GetInteger( secondNumber)) {
                    return "More";
                } else if (GetInteger( firstNumber) < GetInteger( secondNumber)) {
                    return "Less";
                } else {
                    if (GetFractionalPart( firstNumber) > GetFractionalPart( secondNumber)) {
                        return "More";
                    } else if (GetFractionalPart( firstNumber) < GetFractionalPart( secondNumber)) {
                        return "Less";
                    } else {
                        return "Equal";
                    }
                }
            }
        }
    }
}

int main() {
    std::string firstNumber;
    std::string secondNumber;

    std::cout << "Enter first number: ";
    std::cin >> firstNumber;
    std::cout << "Enter second number: ";
    std::cin >> secondNumber;

    if (CheckNumber( firstNumber) && CheckNumber( secondNumber)) {
        std::cout << CompareNumbers ( firstNumber,secondNumber) << std::endl;
    } else {
        std::cout << "Input Error!" << std::endl;
    }

    return 0;
}

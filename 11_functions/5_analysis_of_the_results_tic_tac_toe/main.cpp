#include <iostream>
#include <string>

int GetNumberCharacters (const std::string& firstLine, const std::string& secondLine, const std::string& thirdLine, char symbol) {
    int result = 0;

    for (int i = 0; i < 3; i++) {
        if (firstLine[i] == symbol) {
            result++;
        }
        if (secondLine[i] == symbol) {
            result++;
        }
        if (thirdLine[i] == symbol) {
            result++;
        }
    }
    return result;
}

bool ChekCorrectSymbols (char symbol) {
    if (symbol == 'X' || symbol == 'O' || symbol == '.') {
        return true;
    } else {
        return false;
    }
}

bool CheckInput (const std::string& firstLine, const std::string& secondLine, const std::string& thirdLine) {
    if (firstLine.length() != 3 && secondLine.length() != 3 && thirdLine.length() != 3) {
        return false;
    } else {
        for (int i = 0; i < 3; i++) {
            if (!ChekCorrectSymbols(firstLine[i]) || !ChekCorrectSymbols(secondLine[i]) || !ChekCorrectSymbols(thirdLine[i])) {
                return false;
            }
        }
        return true;
    }
}

bool CheckVictory (const std::string& firstLine, const std::string& secondLine, const std::string& thirdLine, char symbol) {
    if (firstLine[0] == symbol && firstLine[1] == symbol && firstLine[2] == symbol ||
            secondLine[0] == symbol && secondLine[1] == symbol && secondLine[2] == symbol ||
            thirdLine[0] == symbol && thirdLine[1] == symbol && thirdLine[2] == symbol) {
        return true;
    } else if (firstLine[0] == symbol && secondLine[1] == symbol && thirdLine[2] == symbol ||
               thirdLine[0] == symbol && secondLine[1] == symbol && firstLine[2] == symbol) {
        return true;
    } else {
        for (int i = 0; i < 3; i++) {
            if (firstLine[i] == symbol && secondLine[i] == symbol && thirdLine[i] == symbol) {
                return true;
            }
        }
        return false;
    }
}

std::string CheckResult (const std::string& firstLine, const std::string& secondLine, const std::string& thirdLine) {
    if (CheckInput( firstLine, secondLine, thirdLine)) {
        int crossesNumber = GetNumberCharacters( firstLine, secondLine, thirdLine, 'X');
        int zerosNumber = GetNumberCharacters( firstLine, secondLine, thirdLine, 'O');

        if (crossesNumber == zerosNumber || crossesNumber - 1 == zerosNumber) {
            if (CheckVictory(firstLine, secondLine, thirdLine, 'X')) {
                if (crossesNumber - 1 == zerosNumber) {
                    return "Petya won!";
                } else {
                    return "Incorrect";
                }
            } else if (CheckVictory(firstLine, secondLine, thirdLine, 'O')) {
                if (crossesNumber == zerosNumber) {
                    return "Vasya won!";
                } else {
                    return "Incorrect";
                }
            } else {
                return "Nobody";
            }
        } else {
            return "Incorrect";
        }
    } else {
        return "Incorrect";
    }
}

int main() {
    std::string firstLine;
    std::string secondLine;
    std::string thirdLine;

    std::cout << "Fill in the field (a cross is indicated by an X (English capital letter X),"
                 " a zero by an O (capital Latin letter O), an empty cell by a dot):" << std::endl;

    std::cin >> firstLine >> secondLine >> thirdLine;
    std::cout << CheckResult( firstLine, secondLine, thirdLine) << std::endl;

    return 0;
}

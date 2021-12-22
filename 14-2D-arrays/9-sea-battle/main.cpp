#include <iostream>
#include <string>

void PrintField (char (&field)[10][10]) {
    std::cout << "    A  B  C  D  E  F  G  H  I  J" << std::endl;
    std::cout << "  +------------------------------+" << std::endl;

    for (int i = 0; i < 10; i++) {
        if (i < 9) {
            std::cout << " " << i + 1 << "|";
        } else {
            std::cout << i + 1 << "|";
        }

        for (int j = 0; j < 10; j++) {
            std::cout << " " << field[i][j] << " ";
        }

        std::cout << "|" << std::endl;
    }
    std::cout << "  +------------------------------+" << std::endl;
}

void PrintBattle (char (&opponentField)[10][10], char (&playerField)[10][10]) {
    std::cout << "============================================================================" << std::endl;
    std::cout << "         Opponent's field                              Your field" << std::endl;
    std::cout << "    A  B  C  D  E  F  G  H  I  J              A  B  C  D  E  F  G  H  I  J" << std::endl;
    std::cout << "  +------------------------------+          +------------------------------+" << std::endl;

    for (int i = 0; i < 10; i++) {
        if (i < 9) {
            std::cout << " " << i + 1 << "|";
        } else {
            std::cout << i + 1 << "|";
        }

        for (int j = 0; j < 10; j++) {
            if (opponentField[i][j] == '*') {
                std::cout << " " << opponentField[i][j] << " ";
            } else if (opponentField[i][j] == 'X') {
                std::cout << " " << opponentField[i][j] << " ";
            } else {
                std::cout << "   ";
            }
        }

        std::cout << "|        ";

        if (i < 9) {
            std::cout << " " << i + 1 << "|";
        } else {
            std::cout << i + 1 << "|";
        }

        for (int j = 0; j < 10; j++) {
            std::cout << " " << playerField[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "  +------------------------------+          +------------------------------+" << std::endl;
}

void InputCoordinate (const std::string& message, int shipNumber, int& inputX, int& inputY) {
    std::string userInput;
    bool inputCorrect = false;

    do {
        std::cout << message << shipNumber << " (example A10): ";
        std::cin >> userInput;

        if (userInput.length() == 3) {
            if (userInput[1] == '1' && userInput[2] == '0') {
                if (userInput[0] >= 'A' && userInput[0] <= 'J') {
                    inputX = (int)(userInput[0] - 'A');
                    inputY = 9;
                    inputCorrect = true;
                }
            }
        } else if (userInput.length() == 2) {
            if (userInput[1] >= '1' && userInput[1] <= '9') {
                if (userInput[0] >= 'A' && userInput[0] <= 'J') {
                    inputX = (int)(userInput[0] - 'A');
                    inputY = (int)(userInput[1] - '1');
                    inputCorrect = true;
                }
            }
        }
    } while (!inputCorrect);
}

void InputCoordinate (const std::string& message, int& inputX, int& inputY) {
    std::string userInput;
    bool inputCorrect = false;

    do {
        std::cout << message << " (example A10): ";
        std::cin >> userInput;

        if (userInput.length() == 3) {
            if (userInput[1] == '1' && userInput[2] == '0') {
                if (userInput[0] >= 'A' && userInput[0] <= 'J') {
                    inputX = (int)(userInput[0] - 'A');
                    inputY = 9;
                    inputCorrect = true;
                }
            }
        } else if (userInput.length() == 2) {
            if (userInput[1] >= '1' && userInput[1] <= '9') {
                if (userInput[0] >= 'A' && userInput[0] <= 'J') {
                    inputX = (int)(userInput[0] - 'A');
                    inputY = (int)(userInput[1] - '1');
                    inputCorrect = true;
                }
            }
        }
    } while (!inputCorrect);
}

bool FreeArea (int x, int y, char (&field)[10][10]) {
    int startX, startY, endX, endY;

    if (x == 0) {
        startX = x;
    } else {
        startX = x - 1;
    }

    if (y == 0) {
        startY = y;
    } else {
        startY = y - 1;
    }

    if (x == 9) {
        endX = x;
    } else {
        endX = x + 1;
    }

    if (y == 9) {
        endY = y;
    } else {
        endY = y + 1;
    }

    for (int i = startY; i <= endY; i++) {
        for (int j = startX; j <= endX; j++) {
            if (field[i][j] != ' ') {
                std::cout << "Ships must be spaced one square apart." << std::endl;
                return false;
            }
        }
    }
    return true;
}

void ArrangeShips (const std::string& message, int decksNumber, int shipsNumber, char (&field)[10][10]) {
    std::cout << std::endl;
    std::cout << message << std::endl;

    for (int i = 0; i < shipsNumber; i++) {
        PrintField( field);

        if (decksNumber == 1) {
            int x, y;

            do {
                InputCoordinate("Enter the coordinates of the ship No.", i + 1, x, y);
            } while (!FreeArea( x, y, field));

            field[y][x] = 'S';
        } else {
            int startX, startY, endX, endY;
            bool CorrectRelativePositionOfPoints = false;

            do {
                InputCoordinate("Enter the coordinates of the start of the ship No.", i + 1, startX, startY);
                InputCoordinate("Enter the coordinates of the end of the ship No.", i + 1, endX, endY);

                CorrectRelativePositionOfPoints = startX == endX && startY == endY + decksNumber - 1 ||
                                                  startX == endX && startY == endY - decksNumber + 1 ||
                                                  startY == endY && startX == endX + decksNumber - 1 ||
                                                  startY == endY && startX == endX - decksNumber + 1;


            } while (!(FreeArea( startX, startY, field) && FreeArea( endX, endY, field) && CorrectRelativePositionOfPoints));

            int temporaryVariable;

            if (startX > endX) {
                temporaryVariable = startX;
                startX = endX;
                endX = temporaryVariable;
            }

            if (startY > endY) {
                temporaryVariable = startY;
                startY = endY;
                endY = temporaryVariable;
            }

            for (int j = startY; j <= endY; j++) {
                for (int k = startX; k <= endX; k++) {
                    field[j][k] = 'S';
                }
            }
        }
    }
}

void FillThePlayingField (const std::string& message, char (&field)[10][10]) {
    std::cout << "+-----------------------------------------+" << std::endl;
    std::cout << message << std::endl;

    std::fill_n(&field[0][0], sizeof(field) / sizeof(**field), ' ');

    ArrangeShips("Placement of 4 boats (length 1):", 1, 4, field);
    ArrangeShips("Placement of 3 corvettes (length 2):", 2, 3, field);
    ArrangeShips("Placement of 2 destroyers (length 3):", 3, 2, field);
    ArrangeShips("Placement of 1 cruiser (length 4):", 4, 1, field);
}

void FillAreaAroundShip (char (&field)[10][10], int& startX, int& startY, int& endX, int& endY) {
    for (int j = startY; j <= endY; j++) {
        for (int k = startX; k <= endX; k++) {
            if (field[j][k] != 'X') {
                field[j][k] = '*';
            }
        }
    }
}

bool ShipDestroyed (char (&field)[10][10], int& x, int& y) {
    int startX, startY, endX, endY;

    if (y < 9) {
        bool damagedDeckFound = true;

        for (int i = y + 1; damagedDeckFound; i++) {
            if (field[i][x] == 'S') {
                return false;
            } else if (field[i][x] == '*' || field[i][x] == ' ' || field[i][x] == 'X' && i == 9) {
                damagedDeckFound = false;
                endY = i;
            }
        }
    } else {
        endY = y;
    }

    if (y > 0) {
        bool damagedDeckFound = true;

        for (int i = y - 1; damagedDeckFound; i--) {
            if (field[i][x] == 'S') {
                return false;
            } else if (field[i][x] == '*' || field[i][x] == ' ' || field[i][x] == 'X' && i == 0) {
                damagedDeckFound = false;
                startY = i;
            }
        }
    } else {
        startY = y;
    }

    if (x < 9) {
        bool damagedDeckFound = true;

        for (int i = x + 1; damagedDeckFound; i++) {
            if (field[y][i] == 'S') {
                return false;
            } else if (field[y][i] == '*' || field[y][i] == ' ' || field[y][i] == 'X' && i == 9) {
                damagedDeckFound = false;
                endX = i;
            }
        }
    } else {
        endX = x;
    }

    if (x > 0) {
        bool damagedDeckFound = true;

        for (int i = x - 1; damagedDeckFound; i--) {
            if (field[y][i] == 'S') {
                return false;
            } else if (field[y][i] == '*' || field[y][i] == ' ' || field[i][y] == 'X' && i == 0) {
                damagedDeckFound = false;
                startX = i;
            }
        }
    } else {
        startX = x;
    }

    FillAreaAroundShip ( field, startX, startY, endX, endY);
    return true;
}

bool PlayerStep (const std::string& message, int& numberOfHits, char (&opponentField)[10][10]) {
    std::cout << std::endl;
    std::cout << message << std::endl;

    int x, y;

    do {
        InputCoordinate("Enter the coordinates for the shot ", x, y);

        if (opponentField[y][x] == '*' || opponentField[y][x] == 'X') {
            std::cout << "You have already fired at these coordinates." << std::endl;
        }
    } while (opponentField[y][x] != ' ' && opponentField[y][x] != 'S');

    if (opponentField[y][x] == ' ') {
        opponentField[y][x] = '*';
        return false;
    } else if (opponentField[y][x] == 'S') {
        opponentField[y][x] = 'X';
        numberOfHits++;
        if (ShipDestroyed( opponentField, x, y)) {
            std::cout << "Destroyed!" << std::endl;
        } else {
            std::cout << "There is a hit!" << std::endl;
        }
        return true;
    }
}

void TheGame (char (&firstPlayerField)[10][10], char (&secondPlayerField)[10][10]) {
    int firstNumberOfHits = 0;
    int secondNumberOfHits = 0;
    bool hit = false;

    for (int i = 0; firstNumberOfHits != 20 && secondNumberOfHits != 20 ; i++) {
        if (i % 2 == 0) {

            do {
                PrintBattle ( secondPlayerField, firstPlayerField);
                hit = PlayerStep( "The first player's turn.", firstNumberOfHits, secondPlayerField);
            } while (hit && firstNumberOfHits != 20);
        } else {

            do {
                PrintBattle ( firstPlayerField, secondPlayerField);
                hit = PlayerStep( "The second player's turn.", secondNumberOfHits, firstPlayerField);
            } while (hit && secondNumberOfHits != 20);
        }
    }

    if (firstNumberOfHits == 20) {
        PrintField( secondPlayerField);
        std::cout << "The first player wins!" << std::endl;
    } else if (secondNumberOfHits == 20) {
        PrintField( firstPlayerField);
        std::cout << "The second player wins!" << std::endl;
    }
}

int main() {
    char firstPlayerField [10][10];
    char secondPlayerField [10][10];

    FillThePlayingField( "The first player fills in the field.", firstPlayerField);
    FillThePlayingField( "The second player fills in the field.", secondPlayerField);

    TheGame( firstPlayerField, secondPlayerField);

    return 0;
}

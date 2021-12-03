#include <iostream>
#include <string>

std::string GetPlayerName (const std::string& serialNumber) {
    std::string playerName;
    std::cout << "Enter " << serialNumber << " player name: ";
    std::cin >> playerName;
    return playerName;
}

void PrintPlayingField (const char playingField[][3]) {
    std::cout << "-----" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "|";
        for (char j = 0; j < 3; j++) {
            std::cout << playingField[i][j];
        }
        std::cout << "|" <<  std::endl;
    }
    std::cout << "-----" << std::endl;
}

bool ChekVictory (char symbol, const char playingField[][3]) {
    if (playingField[0][0] == symbol && playingField[1][1] == symbol && playingField[2][2] == symbol
            || playingField[2][0] == symbol && playingField[1][1] == symbol && playingField[0][2] == symbol) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        if (playingField[i][0] == symbol && playingField[i][1] == symbol && playingField[i][2] == symbol
                || playingField[0][i] == symbol && playingField[1][i] == symbol && playingField[2][i] == symbol) {
            return true;
        }
    }
    return false;
}

char CurrentPlayerStep (const std::string& currentPlayer, char symbol, char playingField[][3]) {
    std::cout << currentPlayer << ", your move. Select coordinates (from 1 to 3) on the field to put " << symbol << ":" << std::endl;

    int vertical;
    int horizontal;
    bool inputCorrect;

    do {
        std::cin >> vertical >> horizontal;

        inputCorrect = vertical > 0 && vertical <= 3
                       && horizontal > 0 && horizontal <= 3
                       && playingField[vertical - 1][horizontal - 1] == ' ';

        if (!inputCorrect) {
            std::cout << "Incorrect input, please try again:" << std::endl;
        }
    } while(!inputCorrect);

    playingField[vertical - 1][horizontal - 1] = symbol;
    PrintPlayingField( playingField);

    if (ChekVictory(symbol, playingField)) {
        return symbol;
    } else {
        return ' ';
    }
}

int main() {
    std::string firstPlayerName = GetPlayerName("first");
    std::string secondPlayerName = GetPlayerName("second");
    char firstSymbol = 'X';
    char secondSymbol = 'O';
    char winnerSymbol = ' ';

    char playingField[3][3] = {{' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '}};

    for (int i = 1; i <= 9 && winnerSymbol != firstSymbol && winnerSymbol != secondSymbol; i++) {
        if (i % 2 != 0) {
            winnerSymbol = CurrentPlayerStep( firstPlayerName, firstSymbol, playingField);
        } else {
            winnerSymbol = CurrentPlayerStep( secondPlayerName, secondSymbol, playingField);
        }
    }

    if (winnerSymbol == firstSymbol) {
        std::cout << firstPlayerName << " won!" << std::endl;
    } else if (winnerSymbol == secondSymbol) {
        std::cout << secondPlayerName << " won!" << std::endl;
    } else {
        std::cout << "Draw!" << std::endl;
    }
    return 0;
}

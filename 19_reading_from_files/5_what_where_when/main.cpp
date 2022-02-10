#include <iostream>
#include <fstream>
#include <string>

const int BUFFER_SIZE = 100;

void Initialize (bool (&array)[13]) {
    for (bool & i : array) {
        i = true;
    }
}

int main() {
    std::string folderPath;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;

    int currentSector = 0;
    int playerPoints = 0;
    int spectatorPoints = 0;
    bool fileFound = true;

    bool sectorStatus[13];
    Initialize( sectorStatus);

    while (playerPoints < 6 && spectatorPoints < 6 && fileFound) {
        std::ifstream file;
        int sectorOffset;

        // Sector offset
        std::cout << "Enter sector offset: ";
        std::cin >> sectorOffset;
        currentSector += sectorOffset;

        if (currentSector >= 13) {
            currentSector %= 13;
        }

        while ( !sectorStatus[ currentSector]) {
            if (currentSector < 13) {
                currentSector++;
            }
            else {
                currentSector = 0;
            }
        }
        sectorStatus[ currentSector] = false;

        // Question
        file.open(folderPath + "\\q" + std::to_string(currentSector) + ".txt", std::ios::binary);

        if (file.is_open()) {
            std::cout << "Question N" << currentSector + 1 << ":" << std::endl;
            char buffer[BUFFER_SIZE + 1];

            while (!file.eof()) {
                file.read(buffer, BUFFER_SIZE);
                buffer[file.gcount()] = '\0';
                std::cout << buffer;
            }
            std::cout << std::endl;
            file.close();

            // Answer
            file.open( folderPath + "\\a" + std::to_string( currentSector) + ".txt");

            if (file.is_open()) {
                std::cout << "Enter your answer: ";
                std::string answer,
                            temp;

                std::cin >> answer;
                file >> temp;

                if (answer == temp) {
                    playerPoints++;
                    std::cout << "Right! The player gets 1 point. Total:" << playerPoints << std::endl;
                }
                else {
                    spectatorPoints++;
                    std::cout << "Not true. Spectators get 1 point. Total:" << spectatorPoints << std::endl;
                }

                file.close();
            }
            else {
                std::cout << "Response file not found." << std::endl;
                fileFound = false;
            }
        }
        else {
            std::cout << "Question file not found." << std::endl;
            fileFound = false;
        }
    }

    if (playerPoints >= 6) {
        std::cout << "The player has won!" << std::endl;
    }
    else if (spectatorPoints >= 6) {
        std::cout << "The viewers have won!" << std::endl;
    }
    return 0;
}

/*
    Задание 5. Реализация игры «Что? Где? Когда?»

    Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».

    Как происходит игра
    В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. Всего таких
секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане.
Исходя из этого офсета вычисляется новый активный сектор, который и будет играть в этом ходе. Если выпавший сектор уже
играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.

    Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора.
Вопрос показывается на экране.

    После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода.
То, что он ввёл, сравнивается с ответом, который хранится во втором файле, ассоциированном с активным сектором. Данный
файл должен содержать лишь одно слово-ответ.

    Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.

    Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель
и программа заканчивает работу.
*/
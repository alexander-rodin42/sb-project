#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

const int MAP_SIZE = 20;

struct Character {
    std::string name{};
    int health{};
    int armor{};
    int damage{};
    int xPosition{};
    int yPosition{};
    int team{};

    void SetEnemyParameters (const std::string& nameChar) {
        this->name = nameChar;
        this->health = (rand() % 100) + 50;
        this->armor = rand() % 50;
        this->damage = (rand() % 15) + 15;
    }

    void SetPlayerParameters () {
        std::cout << "Enter character name: ";
        std::cin >> this->name;

        do {
            std::cout << "Enter the amount of character health: ";
            std::cin >> this->health;
        } while (this->health < 1);

        do {
            std::cout << "Enter the amount of character armor: ";
            std::cin >> this->armor;
        } while (this->armor < 1);

        do {
            std::cout << "Enter the amount of character damage: ";
            std::cin >> this->damage;
        } while (this->damage < 1);
    }
};

void CreateCharacters(std::vector<Character>& characters, const int& numberEnemy) {
    for (int i = 0; i <= numberEnemy; i++) {
        characters.emplace_back();

        if (i == 0) {
            characters[i].SetPlayerParameters();
            characters[i].xPosition = rand() % MAP_SIZE;
            characters[i].yPosition = rand() % MAP_SIZE;
            characters[i].team = 0;

        }
        else {
            characters[i].SetEnemyParameters("Enemy #" + std::to_string(i));
            characters[i].team = 1;

            bool differentCoordinates;
            do {
                differentCoordinates = true;
                characters[i].xPosition = rand() % MAP_SIZE;
                characters[i].yPosition = rand() % MAP_SIZE;
                for (int j = 0; j < characters.size() - 1; j++) {
                    if (characters[i].xPosition == characters[j].xPosition
                            && characters[i].yPosition == characters[j].yPosition) {
                        differentCoordinates = false;
                    }
                }
            } while ( !differentCoordinates);
        }
    }
}

void PrintCharacter (Character& character) {
    std::cout << "Name:   " << character.name << std::endl;
    std::cout << "Health: " << character.health << std::endl;
    std::cout << "Armor:  " << character.armor << std::endl;
    std::cout << "Damage: " << character.damage << std::endl;
    std::cout << "X pos.: " << character.xPosition + 1 << std::endl;
    std::cout << "Y pos.: " << character.yPosition + 1 << std::endl;
    std::cout << std::endl;
}

void SaveGame (std::vector<Character>& characters) {
    std::ofstream outFile;
    std::string folderPath;
    std::string fileName;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    outFile.open(folderPath + "\\" + fileName + ".bin", std::ios::binary);

    int charactersNumber = characters.size();
    outFile.write( (char*)&charactersNumber, sizeof(charactersNumber));

    for (int i = 0; i < charactersNumber; i++) {
        int nameLength = characters[i].name.length();
        outFile.write( (char*)&nameLength, sizeof(nameLength));
        outFile.write( characters[i].name.c_str(), nameLength);
        outFile.write( (char*)&characters[i].health, sizeof(characters[i].health));
        outFile.write( (char*)&characters[i].armor, sizeof(characters[i].armor));
        outFile.write( (char*)&characters[i].damage, sizeof(characters[i].damage));
        outFile.write( (char*)&characters[i].xPosition, sizeof(characters[i].xPosition));
        outFile.write( (char*)&characters[i].yPosition, sizeof(characters[i].yPosition));
        outFile.write( (char*)&characters[i].team, sizeof(characters[i].team));
    }
    outFile.close();
    std::cout << "Game Saved!" << std::endl;
}

void LoadGame (std::vector<Character>& characters) {
    std::ifstream inFile;
    std::string folderPath;
    std::string fileName;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    inFile.open(folderPath + "\\" + fileName + ".bin", std::ios::binary);

    if ( !inFile.is_open()) {
        std::cout << "No file with that name was found." << std::endl;
    }
    else {
        int charactersNumber;
        inFile.read( (char*)&charactersNumber, sizeof(charactersNumber));

        for (int i = 0; i < charactersNumber; i++) {
            characters.emplace_back();

            int nameLength;
            inFile.read( (char*)&nameLength, sizeof(nameLength));
            characters[i].name.resize( nameLength);
            inFile.read( (char*)characters[i].name.c_str(), nameLength);
            inFile.read( (char*)&characters[i].health, sizeof(characters[i].health));
            inFile.read( (char*)&characters[i].armor, sizeof(characters[i].armor));
            inFile.read( (char*)&characters[i].damage, sizeof(characters[i].damage));
            inFile.read( (char*)&characters[i].xPosition, sizeof(characters[i].xPosition));
            inFile.read( (char*)&characters[i].yPosition, sizeof(characters[i].yPosition));
            inFile.read( (char*)&characters[i].team, sizeof(characters[i].team));
        }
        inFile.close();
    }
}

void FillMap (char (&map)[MAP_SIZE][MAP_SIZE]) {
    for (auto & i : map) {
        for (char & j : i) {
            j = '.';
        }
    }
}

void PrintMap (char (&map)[MAP_SIZE][MAP_SIZE]) {
    std::cout << "  +";
    for (int i = 0; i < MAP_SIZE; i++) {
        std::cout << "---";
    }
    std::cout << "+" << std::endl;

    for (int i = MAP_SIZE - 1; i >= 0; i--) {
        if (i < 9) {
            std::cout << " ";
        }
        std::cout << i + 1 << "|";
        for (int j = 0; j < MAP_SIZE; j++) {
            std::cout << " " << map[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "  +";
    for (int i = 0; i < MAP_SIZE; i++) {
        std::cout << "---";
    }
    std::cout << "+" << std::endl;
    std::cout << "   ";
    for (int i = 0; i < MAP_SIZE; i++) {
        std::cout << " " << i + 1;
        if (i < 9) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void UpdatePosition (char (&map)[MAP_SIZE][MAP_SIZE], std::vector<Character>& characters) {
    FillMap( map);

    for (int i = 0; i < characters.size(); i++) {
        if (characters[i].health > 0) {
            if (i == 0) {
                map[characters[i].yPosition][characters[i].xPosition] = 'P';
            }
            else {
                map[characters[i].yPosition][characters[i].xPosition] = 'E';
            }
        }
    }
}

bool CheckCommand (const std::string (&possibleCommands)[11], const std::string& inputCommand) {
    for (auto & command : possibleCommands) {
        if (inputCommand == command) {
            return true;
        }
    }
    return false;
}

void InputCommand (std::string& command) {
    std::string possibleCommands[11] = {"w", "a", "s", "d", "top", "left", "bottom", "right", "save", "load", "print"};
    std::cout << "Possible commands: ";

    for (int i = 0; i < 10; i++) {
        std::cout << "\"" << possibleCommands[i] << "\"";

        if (i < 8) {
            std::cout << ", ";
        }
        else {
            std::cout << ". ";
        }
    }
    std::cout << std::endl;

    do {
        std::cout << "Enter the command: ";
        std::cin >> command;
    } while ( !CheckCommand(possibleCommands, command));

}

bool CheckEndGame (std::vector<Character>& characters) {
    if (characters[0].health <= 0) {
        return true;
    } else {
        int sumEnemyHealth = 0;
        for (int i = 1; i < characters.size(); i++) {
            sumEnemyHealth += characters[i].health;
        }
        if (sumEnemyHealth <= 0) {
            return true;
        }
    }
    return false;
}

void CheckOutsideTheMap (int & x, int & y) {
    if (x < 0) {
        x = 0;
    }
    else if (x > MAP_SIZE - 1) {
        x = MAP_SIZE - 1;
    }

    if (y < 0) {
        y = 0;
    }
    else if (y > MAP_SIZE - 1) {
        y = MAP_SIZE - 1;
    }
};

void MakeDamage (Character & source, Character & target) {
    std::cout << source.name << " deals (" << source.damage << ") damage to an " << target.name << "!" << std::endl;
    target.armor -= source.damage;
    if (target.armor < 0) {
        target.health += target.armor;
        target.armor = 0;
    }

    if (target.health < 0) {
        target.health = 0;
    }
}

bool CheckPosition (int & x, int & y, Character & currentCharacter , std::vector<Character>& targets) {
    for (auto & target : targets) {
        if (target.xPosition == x && target.yPosition == y && target.health > 0) {
            if (currentCharacter.team != target.team) {
                MakeDamage(currentCharacter, target);
            }
            return true;
        }
    }
    return false;
}

void MovePlayer (const std::string& command, std::vector<Character>& characters) {
    int xTarget = characters[0].xPosition;
    int yTarget = characters[0].yPosition;

    if (command == "w" || command == "top") {
        yTarget++;
    }
    else if (command == "a" || command == "left") {
        xTarget--;
    }
    else if (command == "s" || command == "bottom") {
        yTarget--;
    }
    else {
        xTarget++;
    }

    CheckOutsideTheMap(xTarget, yTarget);

    if ( !CheckPosition(xTarget, yTarget, characters[0], characters)) {
        characters[0].xPosition = xTarget;
        characters[0].yPosition = yTarget;
    }
}

void MoveEnemy (Character & currentCharacter, std::vector<Character>& characters) {
    int xTarget = currentCharacter.xPosition;
    int yTarget = currentCharacter.yPosition;
    int direction = rand() % 4;

    if (direction == 0) {
        yTarget++;
    }
    else if (direction == 1) {
        xTarget--;
    }
    else if (direction == 2) {
        yTarget--;
    }
    else {
        xTarget++;
    }

    CheckOutsideTheMap(xTarget, yTarget);

    if ( !CheckPosition(xTarget, yTarget, currentCharacter, characters)) {
        currentCharacter.xPosition = xTarget;
        currentCharacter.yPosition = yTarget;
    }
}

void GameCycle (std::string& command, std::vector<Character>& characters, char (&map)[MAP_SIZE][MAP_SIZE]) {
    do {
        UpdatePosition( map, characters);
        PrintMap( map);
        InputCommand( command);

        if (command == "save") {
            SaveGame( characters);
        }
        else if (command == "load") {
            LoadGame( characters);
        }
        else if (command == "print") {
            for (auto & character : characters) {
                PrintCharacter( character);
            }
        }
        else {
            MovePlayer( command, characters);

            for (int i = 1; i < characters.size(); i++) {
                if (characters[i].health > 0) {
                    MoveEnemy( characters[i], characters);
                }
            }
        }
    } while ( !CheckEndGame( characters));
}

int main() {
    std::srand(std::time(nullptr));
    char map[MAP_SIZE][MAP_SIZE];
    std::vector<Character> characters;
    std::string command;

    do {
        std::cout << R"(Enter "new" to start a new game or "load" to load a saved game: )";
        std::cin >> command;
    } while ( !(command == "new" || command == "load"));

    if (command == "new") {
        CreateCharacters(characters, 5);
    } else {
        LoadGame( characters);
    }

    GameCycle( command, characters, map);

    if (characters[0].health <= 0) {
        std::cout << characters[0].name << " lose." << std::endl;
    }
    else {
        std::cout << characters[0].name << " won." << std::endl;
    }
    return 0;
}


/*
Задание 4. Реализация ролевой пошаговой игры

    Реализуйте сильно упрощённую версию ролевой пошаговой игры:

    Игра происходит на карте размером 40 на 40 клеток. По клеткам перемещаются враги и персонаж игрока.

    После каждого хода игрока карта показывается вновь со всеми врагами на ней. Игрок помечается буквой P.
Враги буквой E. Пустые места — точкой.

    Каждый персонаж игры представлен в виде структуры с полями: имя, жизни, броня, урон.

    Вначале игры создаются 5 случайных врагов в случайных клетках карты. Имена врагам задаются в формате “Enemy #N”,
где N — это порядковый номер врага. Уровень жизней врагам задаётся случайно, от 50 до 150. Уровень брони варьируется
от 0 до 50. Урон тоже выбирается случайно от 15 до 30 единиц.

    Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя.

    Все персонажи появляются в случайных местах карты.

    Игрок осуществляет ход с помощью команд: left, right, top, bottom. В зависимости от команды и выбирается
направление перемещения персонажа: влево, вправо, вверх, вниз.

    Враги перемещаются в случайном направлении.

    Если персонаж (враг или игрок) перемещается в сторону, где уже находится какой-то персонаж, то он бьёт этого
персонажа с помощью своего урона. Враги при этом никогда не бьют врагов, а просто пропускают ход и остаются на своём
месте. За пределы карты (40 на 40 клеток) ходить нельзя никому. Если кто-то выбрал направление за гранью дозволенного,
ход пропускается.

    Формула для расчёта урона совпадает с той, что была в самом уроке. Жизни уменьшаются на оставшийся после брони урон.
При этом сама броня тоже сокращается на приведённый урон.

    Игра заканчивается тогда, когда либо умирают все враги, либо персонаж игрока. В первом случае на экран выводится
сообщение о поражении, во втором — победа.

    Если в начале хода игрок вводит команду save или load вместо направления перемещения, то игра либо делает сохранение
своего состояния в файл, либо загружает это состояние из файла соответственно.

    Советы и рекомендации

    Для определения команды персонажа можно завести специальный флаг внутри структуры данных персонажа.

    Для отображения координат персонажей можете использовать структуру вектора из другой задачи, но заменить типы
координат.
*/
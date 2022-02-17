#include <iostream>
#include <fstream>
#include <vector>

bool CheckFishName (const std::string& name) {
    for (auto i : name) {
        if (!(i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z')) {
            return false;
        }
    }
    return true;
}

void EnterName (const std::string& message, std::string& name) {
    do {
        std::cout << message;
        std::cin >> name;
    }
    while ( !CheckFishName(name));
}

void ConvertNameToFormat (std::string& name) {
    for (int i = 0; i < name.length(); i++){
        if (name[i] >= 'A' && name[i] <= 'Z') {
            i -= 32;
        }

    }
}

bool FileIsEmpty (const std::string& path) {
    std::ifstream inFile;
    inFile.open (path);

    if (inFile.is_open()) {
        long long fileSize;
        inFile.seekg(0, std::ios::end);
        fileSize = inFile.tellg();
        if (fileSize != 0) {
            return false;
        }
    }
    return true;
}

void CatchFish (const std::string& folderPath, const std::string& fish) {
    std::ifstream inFile;

    inFile.open(folderPath + "\\river.txt");

    if ( !inFile.is_open()) {
        std::cout << "The folderPath to the river was not found!" << std::endl;
    }
    else {
        while ( !inFile.eof()) {
            std::string currentFish;
            inFile >> currentFish;

            if (fish == currentFish) {
                std::ofstream outFile;

                std::cout << "You caught a " << currentFish << "! What you need, put it in the basket." << std::endl;
                outFile.open(folderPath + "\\basket.txt", std::ios::app);

                if ( !FileIsEmpty(folderPath + "\\basket.txt")) {
                    outFile << std::endl;
                }

                outFile << currentFish;
                outFile.close();
            }
            else {
                std::cout << "You caught a " << currentFish << "! You release the fish." << std::endl;
            }
        }
        inFile.close();
    }
}

void Print (const std::vector<std::string>& fish, const std::vector<int>& count) {
    std::cout << "Basket contents:" << std::endl;
    for (int i = 0; i < fish.size(); i++) {
        std::cout << fish[i] << " - " << count[i] << std::endl;
    }
}


void CountFish (const std::string& folderPath) {
    std::ifstream inFile;
    inFile.open( folderPath + "\\basket.txt");

    if ( !inFile.is_open()) {
        std::cout << "The path to the basket was not found!" << std::endl;
    }
    else {
        std::vector<std::string> fishNames{};
        std::vector<int> numberOfFish{};

        while ( !inFile.eof()) {
            std::string currentFish;
            inFile >> currentFish;

            if ( fishNames.empty()) {
                fishNames.push_back( currentFish);
                numberOfFish.push_back(1);
            }
            else {
                for (int i = 0; i < fishNames.size(); i++) {
                    if (fishNames[i] == currentFish) {
                        numberOfFish[i] += 1;
                        break;
                    }
                    else if (i == fishNames.size() - 1) {
                        fishNames.push_back( currentFish);
                        numberOfFish.push_back(1);
                        break;
                    }
                }
            }
        }
        Print( fishNames, numberOfFish);
    }
    inFile.close();
}

int main() {
    std::string fishName;
    std::string folderPath;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;

    EnterName("Enter fish name: ", fishName);
    ConvertNameToFormat( fishName);

    CatchFish( folderPath, fishName);
    CountFish( folderPath);

    return 0;
}

/*
    Задание 3. Реализация симуляции игры «Рыбалка»

    Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt) задаётся список из видов
рыб, которые можно в ней поймать. Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.

    В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы. После этого из
первого файла друг за другом осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах вид совпал с
указанным пользователем, в выходной файл basket.txt (корзинка) записывается этот вид.

    В конце программы показывается, сколько было поймано рыб за текущую ловлю. Программу можно запускать несколько раз,
при этом уже пойманные рыбы должны сохраняться в файле-корзинке.

    Пример содержания исходного файла:

sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp
*/
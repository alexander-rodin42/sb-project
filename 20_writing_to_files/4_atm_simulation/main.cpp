#include <iostream>
#include <fstream>
#include <ctime>

void PrintNumberBanknotes (int (&numberOfBanknotes)[6]) {
    int banknotes[6] = {100, 200, 500, 1000, 2000, 5000};
    int sum = 0;

    for (int i = 0; i < 6; i++) {
        std::cout << banknotes[i] << " - " << numberOfBanknotes[i] << std::endl;
        sum += banknotes[i] * numberOfBanknotes[i];
    }
    std::cout << "Total amount: "   << sum << std::endl;
    std::cout << "-----------------------" << std::endl;
}

void FillBank (const std::string& path) {
    int numberOfBanknotes[] = {0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 1000; i++) {
        int banknoteNumber = rand() % 6;
        numberOfBanknotes[ banknoteNumber]++;
    }

    std::ofstream outFile;
    outFile.open( path + "\\bank.bin", std::ios::binary);

    for (auto i : numberOfBanknotes) {
        outFile.write((char*)&i, sizeof(i));
    }

    std::cout << "The banknotes were placed in the ATM:" << std::endl;
    PrintNumberBanknotes( numberOfBanknotes);
    outFile.close();
}

void GetBank (const std::string& path, int (&numberOfBanknotes)[6]) {
    std::ifstream inFile;
    inFile.open( path + "\\bank.bin", std::ios::binary);

    if ( !inFile.is_open()) {
        std::cout << "The path to the bank was not found." << std::endl;
    }
    else {
        for (int i = 0; i < 6; i++) {
            inFile.read((char*)&numberOfBanknotes[i], sizeof(i));
        }
    }
    inFile.close();
}

void SelectBanknotes (const int (&banknotesInBank)[6], int& amountRequired, int (&necessaryBanknotes)[6]) {
    int banknotes[6] = {100, 200, 500, 1000, 2000, 5000};

    //// ошибка тут.
    for (int i = 5; i >= 0; i--) {
        if (amountRequired >= banknotes[i] && banknotesInBank[i] > 0) {
            if (banknotesInBank[i] < amountRequired / banknotes[i]) {
                necessaryBanknotes[i] = banknotesInBank[i];
                amountRequired -= banknotesInBank[i] * banknotes[i];
            }
            else {
                necessaryBanknotes[i] = amountRequired / banknotes[i];
                amountRequired %= banknotes[i];
            }
        }
    }
}

void ExtractBanknotes (const std::string& path, int (&banknotesInBank)[6], const int (&necessaryBanknotes)[6]) {
    for (int i = 0; i < 6; i++) {
        banknotesInBank[i] -= necessaryBanknotes[i];
    }

    std::ofstream outFile;
    outFile.open( path + "\\bank.bin", std::ios::binary);

    for (auto i : banknotesInBank) {
        outFile.write((char*)&i, sizeof(i));
    }

    std::cout << "Banknotes left in the ATM:" << std::endl;
    PrintNumberBanknotes(  banknotesInBank);
    outFile.close();
}

void GiveOutMoney (const std::string& path) {
    int amountRequired;

    do {
        std::cout << "Enter the desired amount: ";
        std::cin >> amountRequired;
    }
    while (amountRequired < 100 || amountRequired % 100 != 0);

    int banknotesInBank[6] = {0, 0, 0, 0, 0, 0};
    int necessaryBanknotes[6] = {0, 0, 0, 0, 0, 0};
    GetBank(path, banknotesInBank);
    //PrintNumberBanknotes( banknotesInBank);

    SelectBanknotes( banknotesInBank, amountRequired, necessaryBanknotes);

    if (amountRequired != 0) {
        std::cout << "There are not enough banknotes in the ATM to dispense the required amount." << std::endl;
    }
    else {
        std::cout << "Banknotes issued:" << std::endl;
        PrintNumberBanknotes( necessaryBanknotes);
        ExtractBanknotes( path, banknotesInBank, necessaryBanknotes);
    }
}

int main() {
    std::srand(std::time(nullptr));
    std::string folderPath;
    std::string userInput;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;

    do {
        std::cout << R"(Enter "+" to replenish the bank, "-" to withdraw money: )";
        std::cin >> userInput;
    } while ( !(userInput == "+" || userInput == "-"));

    if (userInput == "+") {
        FillBank( folderPath);
    }
    else {
        GiveOutMoney( folderPath);
    }
    return 0;
}


/*
    Задание 4. Реализация симуляции банкомата

    Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут храниться только бумажные купюры
номиналом от 100 до 5000 рублей. Максимально в банкомате может храниться только 1000 купюр. Все они записываются в
отдельный файл. У банкомата, как у устройства, две основных операции — снятие денег пользователем и наполнение деньгами
инкассаторами банка.

    Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”.  Количество купюр
рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются случайным образом.

    Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем денег. Пользователь
указывает сумму с точностью до 100 рублей. Мы будем считать, что каждый клиент обладает неограниченным балансом в системе
и теоретически может снять любую сумму. На практике, если данная сумма не может быть снята из-за отсутствия подходящих
денег в машине, показывается сообщение, что эта операция невозможна.

    После выполнения любой из операций программа завершает выполнение. Состояние банкомата должно храниться в отдельном
бинарном файле, автономно.

    Советы и рекомендации:

    Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями.
*/
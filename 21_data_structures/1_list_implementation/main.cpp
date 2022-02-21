#include <iostream>
#include <fstream>
#include <string>

struct Person {
    std::string firstName;
    std::string lastName;
    std::string paymentDate;
    int         amountMoney = 0;

    void SetParameters (const Person& other) {
        this->firstName = other.firstName;
        this->lastName = other.lastName;
        this->paymentDate = other.paymentDate;
        this->amountMoney = other.amountMoney;
    }
};

bool CheckName (const std::string& name) {
    for (auto i : name) {
        if (!(i >= 'A' && i <= 'Z' || i >= 'a' && i <= 'z')) {
            return false;
        }
    }
    return true;
}

void ConvertNameToFormat (std::string& name) {
    for (int i = 0; i < name.length(); i++){
        if (i == 0 && name[i] >= 'a' && name[i] <= 'z') {
            name[i] -= 32;
        }
        else if (i != 0 && name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32;
        }
    }
}

std::string EnteringName (const std::string& message) {
    std::string name;

    do {
        std::cout << message;
        std::cin >> name;
    }
    while (!CheckName( name));

    ConvertNameToFormat( name);

    return name;
}

bool ConfirmDateIsCorrect (const int& day, const int& month, const int& year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {
        daysInMonth[2] = 29;
    }

    if (month < 1 || month > 12) {
        std::cout << "The number of months in a year can only be from 1 to 12." << std::endl;
        return false;
    }

    if (day < 1 || day > daysInMonth[month]) {
        std::cout << "There can only be " << daysInMonth[month] << " days in the " << month << "nd month of the year ";
        std::cout << year << "." << std::endl;
        return false;
    }

    return true;
}

bool CheckDate (const std::string& date) {
    if (date.length() != 10) {
        return false;
    }

    if (date[2] != '.' || date[5] != '.') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !(date[i] >= '0' && date[i] <= '9')) {
            return false;
        }
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    if ( !ConfirmDateIsCorrect( day, month, year)) {
        return false;
    }

    return true;
}

std::string EnteringDate (const std::string& message) {
    std::string paymentDate;
    do {
        std::cout << message;
        std::cin >> paymentDate;
    }
    while (!CheckDate( paymentDate));

    return paymentDate;
}

int EnteringAmountMoney (const std::string& message) {
    int amountMoney;

    do {
        std::cout << message;
        std::cin >> amountMoney;
    }
    while (amountMoney < 1);

    return amountMoney;
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

bool ContinueFilling () {
    std::string userInput;

    do {
        std::cout << "Do you want to continue completing the form (yes/no)?" << std::endl;
        std::cin >> userInput;
    }
    while ( !(userInput == "yes" || userInput == "no"));

    if (userInput == "yes") {
        return true;
    }
    else {
        return false;
    }
}

void AddToList (const std::string& folderPath) {
    do {
        Person newCharacter = {EnteringName("Enter first name: "),
                               EnteringName( "Enter last name: "),
                               EnteringDate("Enter payment date (dd.mm.yyyy): "),
                               EnteringAmountMoney( "Enter payout amount (greater than zero): ")};

        std::ofstream outFile;
        outFile.open(folderPath, std::ios::app);

        if ( !FileIsEmpty( folderPath)) {
            outFile << std::endl;
        }

        outFile << newCharacter.firstName << " " << newCharacter.lastName << " ";
        outFile << newCharacter.paymentDate << " " << newCharacter.amountMoney;
        outFile.close();
    }
    while ( ContinueFilling());
}

void ReadList (const std::string& folderPath) {
    std::ifstream inFile;
    inFile.open( folderPath);

    if (!inFile.is_open()) {
        std::cout << "Error. List.txt file not found." << std::endl;
    }
    else {
        Person currentCharacter;
        Person majorCharacter;
        int sum = 0;

        for (int i = 1; !inFile.eof(); i++) {
            inFile >> currentCharacter.firstName >> currentCharacter.lastName;
            inFile >> currentCharacter.paymentDate >> currentCharacter.amountMoney;

            std::cout << i << " - " << currentCharacter.firstName << " " << currentCharacter.lastName << " ";
            std::cout << currentCharacter.paymentDate << " " << currentCharacter.amountMoney << std::endl;

            sum += currentCharacter.amountMoney;

            if (majorCharacter.amountMoney < currentCharacter.amountMoney) {
                majorCharacter.SetParameters( currentCharacter);
            }
        }

        std::cout << "The payout amount is: " << sum << std::endl;
        std::cout << majorCharacter.firstName << " " << majorCharacter.lastName << " received the maximum payout, it is: ";
        std::cout << majorCharacter.amountMoney << std::endl;

        inFile.close();
    }
}

int main() {
    std::string folderPath,
                command;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;

    do {
        std::cout << R"(Type "add" to add a new entry to the end of the list, or "read" to read the list: )";
        std::cin >> command;
    }
    while (!(command == "add" || command == "read"));

    if (command == "add") {
        AddToList( folderPath + "\\list.txt");
    }
    else {
        ReadList( folderPath + "\\list.txt");
    }

    return 0;
}

/*
    Задание 1. Реализация ведомости учёта

    Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет обобщить и дополнить использованием структур.

    Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее — дата выдачи в формате
ДД.ММ.ГГГГ., затем — сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен быть
перевод строки.

    Структура данных записи должна соответствовать указанному формату.

    При старте программы пользователь указывает команду, которую следует осуществить: list или add. Команда read осуществляет
чтение из файла ведомости как и прежде, только уже в структуры данных и отображает их на экране.

    Команда add добавляет новую запись в конец ведомости.

    Советы и рекомендации

    Чтобы определить конец файла, используйте функцию file.eof() как и прежде. Из-за завершающего переноса строки, также
стоит проверить и имя. Если оно было считает пустым, то можно считать, что файл закончился.
*/
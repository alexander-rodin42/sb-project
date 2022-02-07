#include <iostream>
#include <fstream>

int main() {
    std::string filePath;
    std::ifstream list;

    int paymentAmount = 0;
    int maxPayment = 0;
    std::string firstName;
    std::string lastName;

    std::cout << "Enter the path to the list: ";
    std::cin >> filePath;
    list.open(filePath);

    if (list.is_open()) {
        std::string tempFirstName;
        std::string tempLastName;
        std::string tempPaymentDate;
        int         tempAmountMoney;

        while (!list.eof()) {
            list >> tempFirstName >> tempLastName >> tempAmountMoney >> tempPaymentDate;

            paymentAmount += tempAmountMoney;

            if (maxPayment < tempAmountMoney) {
                maxPayment = tempAmountMoney;
                firstName = tempFirstName;
                lastName = tempLastName;
            }
        }

        list.close();
        std::cout << "The payout amount is: " << paymentAmount << std::endl;
        std::cout << firstName << " " << lastName << " received the maximum payout, it is: " << maxPayment << std::endl;
    }
    else {
        std::cout << "Not the right way." << std::endl;
    }
    return 0;
}

/*
    Задание 3. Реализация программы чтения ведомости

    Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую
таблицу:

имя и фамилия человека;
количество денег, которые были выплачены лицу;
дата выплаты в формате ДД.ММ.ГГГГ.

    На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с
максимальной суммой выплат.
*/
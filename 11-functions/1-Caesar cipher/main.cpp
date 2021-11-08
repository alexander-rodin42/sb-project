#include <iostream>
#include <string>

char MoveSymbol (char leftBorder, char rightBorder, int alphabetShift, char symbol) {
    if (alphabetShift > 0) {
        if (symbol > rightBorder - alphabetShift) {
            return (char) (leftBorder + alphabetShift - (rightBorder - symbol) - 1);
        } else {
            return (char) (symbol + alphabetShift);
        }
    } else if (alphabetShift < 0) {
        if (symbol < leftBorder - alphabetShift) {
            return (char) (rightBorder + alphabetShift - (leftBorder - symbol) + 1);
        } else {
            return (char) (symbol + alphabetShift);
        }
    } else {
        return symbol;
    }
}

std::string EncryptCaesar(int alphabetShift, std::string message) {
    std::string result;

    for (int i = 0; i < message.length(); i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            result += MoveSymbol('A', 'Z', alphabetShift, (char) message[i]);
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            result += MoveSymbol('a', 'z', alphabetShift, (char) message[i]);
        } else {
            result += message[i];
        }
    }
    return result;
}

std::string DecryptCaesar(int alphabetShift, std::string message) {
    return EncryptCaesar( -alphabetShift, message);
}

int main() {
    int alphabetShift;
    std::string userMessage;

    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, userMessage);
    std::cout << "Enter the alphabet offset: ";
    std::cin >> alphabetShift;

    std::cout << "Encrypted:" << std::endl;
    std::string result = EncryptCaesar(alphabetShift, userMessage);
    std::cout << result << std::endl;

    std::cout << "Decrypted:" << std::endl;
    result = DecryptCaesar(alphabetShift, result);
    std::cout << result << std::endl;

    return 0;
}

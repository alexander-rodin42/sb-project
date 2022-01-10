#include <iostream>
#include <string>

std::string GetUserName (const std::string& email) {
    std::string result;
    for (int i = 0; email[i] != '@' && i < email.length(); i++) {
        result += email[i];
    }
    return result;
}

std::string GetHostName (const std::string& email) {
    std::string result;
    bool hostStartFound = false;
    for (char i : email) {
        if (hostStartFound) {
            result += i;
        }
        if (i == '@') {
            hostStartFound = true;
        }
    }
    return result;
}

bool CheckUserName (const std::string& userName) {
    if (userName[0] == '.' || userName[userName.length() - 1] == '.') {
        return false;
    }

    std::string allowedCharacters = "!#$%&'*+-/=?^_`{|}~";
    int charactersNumber = 0;

    for (int i = 0; i < userName.length(); i++) {
        if (userName[i] >= 'A' && userName[i] <= 'Z' ||
            userName[i] >= 'a' && userName[i] <= 'z' ||
            userName[i] >= '0' && userName[i] <= '9') {
            charactersNumber++;
        } else if (i > 0 && userName[i] == '.' && userName[i - 1] != '.') {
            charactersNumber++;
        } else {
            bool symbolFound = false;
            for (int j = 0; !symbolFound && j < allowedCharacters.length(); j++) {
                if (userName[i] == allowedCharacters[j]) {
                    charactersNumber++;
                    symbolFound = true;
                }
            }
            if (!symbolFound) {
                return false;
            }
        }
    }
    return charactersNumber > 0 && charactersNumber < 65;
}

bool CheckHostName (const std::string& hostName) {
    if (hostName[0] == '.' || hostName[hostName.length() - 1] == '.') {
        return false;
    }

    int charactersNumber = 0;

    for (int i = 0; i < hostName.length(); i++) {
        if (hostName[i] >= 'A' && hostName[i] <= 'Z' ||
            hostName[i] >= 'a' && hostName[i] <= 'z' ||
            hostName[i] >= '0' && hostName[i] <= '9') {
            charactersNumber++;
        } else if (i > 0 && hostName[i] == '.' && hostName[i - 1] != '.') {
            charactersNumber++;
        } else if (hostName[i] == '-') {
            charactersNumber++;
        } else {
            return false;
        }
    }
    return charactersNumber > 0 && charactersNumber < 64;
}

std::string CheckEmail (const std::string& email) {
    return CheckHostName(GetHostName(email)) && CheckUserName(GetUserName(email)) ? "Yes" : "No";
}

int main() {
    std::string userEmail;
    std::cout << "Enter email: ";
    std::cin >> userEmail;

    if (GetHostName(userEmail).length() == 0) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << CheckEmail(userEmail) << std::endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <map>

bool CheckAnagram (const std::string& first, const std::string& second) {
    if (first.length() != second.length()) {
        return false;
    }

    std::map<char, int> characters;
    for (auto & i : first) {
        ++characters[i];
    }

    for (auto & i : second) {
        if (characters.find(i) == characters.end()) {
            return false;
        }
        else {
            --characters[i];
            if (characters[i] <= 0) {
                characters.erase(i);
            }
        }
    }
    return true;
}

int main() {
    std::string first;
    std::string second;

    std::cout << "Enter first word: ";
    std::cin >> first;
    std::cout << "Enter second word: ";
    std::cin >> second;

    if (CheckAnagram(first, second)) {
        std::cout << "The first line is an anagram of the second." << std::endl;
    }
    else {
        std::cout << "The first line is not an anagram of the second." << std::endl;;
    }

    return 0;
}

/*
    Задание 3. Анаграммы

    Напишите функцию, которая принимает две строки и возвращает true, если первая строка является анаграммой второй
(то есть можно получить первую строку из второй путём перестановки букв местами), и false иначе. Для достижения хорошей
асимптотики решения рекомендуется использовать std::map.

    Пример анаграммы: лекарство — стекловар
*/
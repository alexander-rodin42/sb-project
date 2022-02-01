#include <iostream>
#include <fstream>

int main() {
    std::string word;
    std::ifstream file;
    int wordCounter = 0;

    std::cout << "Enter a word: ";
    std::cin >> word;

    file.open("C:\\Users\\Alexander\\Desktop\\sb-project\\19_reading_from_files\\1_word_search\\words.txt");

    while (!file.eof()) {
        std::string temp;
        file >> temp;

        if (temp == word) {
            wordCounter++;
        }
    }

    file.close();
    std::cout << wordCounter << std::endl;

    return 0;
}

/*
    Задание 1. Разработка программы поиска слов в файле

    Составьте небольшой текстовый файл «words.txt», в котором последовательно, через пробелы и переносы строк расположены
различные слова. Можете использовать любые англоязычные слова. Разработайте программу, которая искала бы среди этих слов
нужное пользователю и выводила бы общее количество повторений этого слова. 0 — если слово вообще не присутствует в файле.
*/
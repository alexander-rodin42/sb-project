#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filePath;
    std::ifstream pngFile;

    std::cout << "Enter the path to the PNG pngFile: ";
    std::cin >> filePath;
    pngFile.open(filePath, std::ios::binary);

    bool checkFileExtension = filePath.substr( filePath.size() - 4, 4) == ".png" ||
                              filePath.substr( filePath.size() - 4, 4) == ".PNG";

    if (pngFile.is_open() && checkFileExtension) {
        char buffer[4];
        pngFile.read(buffer, 4);

        if ( int(buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')) {
            std::cout << "This file is a PNG image." << std::endl;
        }
        else {
            std::cout << "This file is not a PNG image." << std::endl;
        }

        pngFile.close();
    }
    else if (!checkFileExtension) {
        std::cout << "Invalid file extension." << std::endl;
        pngFile.close();
    }
    else {
        std::cout << "Not the right way." << std::endl;
    }


    return 0;
}

/*
    Задание 4. Разработка детектора PNG-файла

    Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу. На выходе программа должна
определить, является ли данный файл PNG-изображением. Данная процедура не просто должна смотреть на расширение файла,
но и произвести минимальный анализ его внутренностей, в бинарном режиме.

    Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. Нас будут интересовать
первые четыре байта. Первый байт всегда имеет значение −119 (число со знаком минус), а следующие — это просто символы
‘P’, ‘N’, ‘G’, расположенные друг за другом. Обратите внимание, что все они в верхнем регистре.

    По результатам проверки пути и внутренностей требуется сообщить пользователю о результате проверки в стандартный
вывод.
*/
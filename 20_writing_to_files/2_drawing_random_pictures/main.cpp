#include <iostream>
#include <ctime>
#include <fstream>

void Input (const std::string& message, int&userInput) {
    do {
        std::cout << message;
        std::cin >> userInput;
    }
    while (userInput < 1);
}

char GenerateSymbol () {
    if (std::rand() % 2 == 0) {
        return '1';
    }
    else {
        return '0';
    }
}

int main() {
    std::srand(std::time(nullptr));

    std::string folderPath;
    int pictureHeight,
        pictureWidth;

    std::cout << "Enter folder path: ";
    std::cin >> folderPath;

    Input("Enter the height of the picture: ", pictureHeight);
    Input("Enter the width of the picture: " , pictureWidth);

    std::ofstream outFile;
    outFile.open(folderPath + "\\pic.txt");

    for (int i = 0; i < pictureHeight; i++) {
        for (int j = 0; j < pictureWidth; j++) {
            outFile << GenerateSymbol();
        }
        outFile << std::endl;
    }
    outFile.close();

    std::cout << "The picture is ready!" << std::endl;

    return 0;
}

/*
    Задание 2. Реализация рисования случайных картин

    С помощью генератора случайных чисел рисуется картинка из нулей и единиц. На вход от пользователя принимается размер
картины: высота и ширина в пикселях. На выходе нужно создать файл pic.txt, содержимое которого будет наполнено случайными
нулями и единицами в рамках размера картины.

    Это ещё не всё. Если вы запустите программу несколько раз на одних и тех же исходных данных (ширина и высота картины),
вы очень скоро обнаружите, что всё время выводится одна и та же картинка. Дело в том, что у генератора случайных чисел
есть ещё и «зерно», от которого он отталкивается. Если это зерно не меняется, то и серия из rand() всегда будет возвращать
одни и те же случайные числа.

    Чтобы разнообразить вывод, вы можете использовать вызов std::srand(std::time(nullptr)); в самом начале программы.
Эта операция задаёт начальное зерно случайных чисел в зависимости от текущего времени. Для её корректной работы не забудьте
также включить заголовочный файл <ctime>.
*/

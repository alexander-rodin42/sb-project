#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 500;

int main() {
    std::string filePath;
    std::ifstream text;

    std::cout << "Enter text path:";
    std::cin >> filePath;
    text.open( filePath, std::ios::binary);

    if (text.is_open()) {
        char command = ' ';
        char buffer[BUFFER_SIZE + 1];

        while (command != 'e' && !text.eof()) {
            text.read(buffer, BUFFER_SIZE);
            buffer[text.gcount()] = 0;
            std::cout << buffer << std::endl << std::endl;

            if (!text.eof()) {
                do {
                    std::cout << "-----------------------------------------" << std::endl;
                    std::cout << R"(Enter "n" to continue, or "e" to exit: )";
                    std::cin >> command;
                    std::cout << "-----------------------------------------" << std::endl;
                } while (!(command == 'e' || command == 'n'));
            }
        }
        std::cout << "----------------------------------" << std::endl;
        std::cout << "The file has been completely read." << std::endl;
        std::cout << "----------------------------------" << std::endl;
        text.close();
    } else {
        std::cout << "Not the right way." << std::endl;
    }
    return 0;
}

/*
    Задание 2. Разработка просмотрщика текстовых файлов

    Разработайте простейший просмотрщик текстовых файлов. В начале программы пользователь вводит путь к текстовому файлу,
который требуется открыть и просмотреть. Внутренности файла необходимо вывести в стандартный вывод. Программа должна
работать для любых текстовых файлов в формате TXT, но вы можете создать и свой отдельный файл для теста. Главное, чтобы
файл был англоязычным, дабы избежать проблем с кодировками.

    Советы и рекомендации
    Для проверки того, был ли на самом деле открыт файл, используйте метод is_open. Он вернёт true, если файл был
благополучно открыт, и false, если что-то пошло не так, к примеру, если путь к файлу невалидный.
    Файл надо считывать постепенно, отдельными фрагментами, ведь он может быть весьма большим. Для этого лучше всего
пользоваться методом gcount, так как он ещё вернёт количество байт, которые были считаны по факту методом read. Сами
эти фрагменты могут храниться в специальном буфере, как и в примере из лекций, но его размер и второй аргумент к функции
read надо рассчитать так, чтобы выводились все символы, без обрезки последней буквы.
    Файл можно открыть в бинарном формате.
*/

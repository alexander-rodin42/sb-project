#include <iostream>

#include "Display.h"

void InputCommand (std::string& command) {
    do {
        std::cout << "> Enter the command: ";
        std::cin >> command;
    }
    while (!(command == "move" ||
             command == "resize" ||
             command == "display" ||
             command == "close"));
}

int main() {
    std::string command;
    Display display;
    Window window;

    window.setCoordinate();
    window.resize();

    do {
        std::cout << "Available commands: move, resize, display, close." << std::endl;
        InputCommand( command);

        if (command == "move") {
            int xShift;
            int yShift;

            std::cout << "Enter the horizontal offset: ";
            std::cin >> xShift;
            std::cout << "Enter vertical offset: ";
            std::cin >> yShift;

            window.move( xShift, yShift);
        }
        else if (command == "resize") {
            window.resize();
        }
        else if (command == "display") {
            display.clean();
            display.paintWindow( window);
            display.print();
        }
    }
    while (command != "close");

    return 0;
}

#include <QApplication>

#include "ImageButton.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ImageButton imageButton(nullptr);

    imageButton.setFixedSize(150, 150);
    imageButton.move(1000, 400);
    imageButton.show();
    return QApplication::exec();
}

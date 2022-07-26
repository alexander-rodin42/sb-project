#include <QApplication>
#include <QFileDialog>

#include "ImageButton.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QString folderPath;
    folderPath = QFileDialog::getExistingDirectory(nullptr,
                                                   "Open folder",
                                                   "C:\\Users\\",
                                                   QFileDialog::DontResolveSymlinks);

    ImageButton imageButton(nullptr, folderPath);

    imageButton.setFixedSize(150, 150);
    imageButton.move(1000, 400);
    imageButton.show();
    return QApplication::exec();
}

#include <QApplication>

#include "./ui_tvRemoteControl.h"
#include "MainTvRemoteControl.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainTvRemoteControl window(nullptr);

    Ui::tvRemoteControl tvRemoteControl;
    tvRemoteControl.setupUi(&window);

    window.label = tvRemoteControl.label;
    window.show();

    return QApplication::exec();
}

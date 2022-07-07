#include <QApplication>
#include <QPushButton>
#include "CalculatorMainWindow.h"
#include "./ui_calculator.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.expressionLineEdit = calculator.expressionLineEdit;
    window.mainLineEdit = calculator.mainLineEdit;

    window.resize(480, 640);
    window.show();
    return QApplication::exec();
}

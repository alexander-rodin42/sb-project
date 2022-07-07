//
// Created by Alexander on 7/5/2022.
//

#ifndef INC_1_GRAPHING_CALCULATOR_CALCULATORMAINWINDOW_H
#define INC_1_GRAPHING_CALCULATOR_CALCULATORMAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QtWidgets/QLineEdit>

enum operation {
    NONE,
    DIVIDE,
    MULTIPLICATION,
    DIFFERENCE,
    SUM,
};

class CalculatorMainWindow : public QMainWindow {
    Q_OBJECT

public:
    CalculatorMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}

    QLineEdit *expressionLineEdit = nullptr;
    QLineEdit *mainLineEdit = nullptr;

public slots:
    void add0();
    void add1();
    void add2();
    void add3();
    void add4();
    void add5();
    void add6();
    void add7();
    void add8();
    void add9();

    void clearExpression();
    void eraseCharacter();
    void divide();
    void multiplication();
    void difference();
    void sum();
    void getResult();
    void dot();
    void changeSign();

private:
    double firstValue{};
    double secondValue{};
    operation currentOperation = NONE;

    static bool checkValueForNull (const QString& qString);
    static QString getQStringOperation (const operation& operation);
    void addNumber (const QChar& qChar) const;
    void chooseOperation (const operation& operation);
};

#endif //INC_1_GRAPHING_CALCULATOR_CALCULATORMAINWINDOW_H

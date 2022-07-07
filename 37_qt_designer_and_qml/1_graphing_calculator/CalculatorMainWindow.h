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
    void add0() { addNumber('0'); }
    void add1() { addNumber('1'); }
    void add2() { addNumber('2'); }
    void add3() { addNumber('3'); }
    void add4() { addNumber('4'); }
    void add5() { addNumber('5'); }
    void add6() { addNumber('6'); }
    void add7() { addNumber('7'); }
    void add8() { addNumber('8'); }
    void add9() { addNumber('9'); }

    void clearExpression() {
        expressionLineEdit->clear();
        mainLineEdit->setText("0");
        currentOperation = NONE;
    }

    void eraseCharacter()  {
        QString temp = mainLineEdit->text();
        if (temp.size() > 1) {
            temp.resize(temp.size() - 1);
            mainLineEdit->setText(temp);
        }
        else {
            mainLineEdit->setText("0");
        }
    }

    void divide()         { chooseOperation(DIVIDE); }
    void multiplication() { chooseOperation(MULTIPLICATION); }
    void difference()     { chooseOperation(DIFFERENCE); }
    void sum()            { chooseOperation(SUM); }

    void getResult() {
        if (currentOperation == NONE) return;

        secondValue = mainLineEdit->text().toDouble();
        expressionLineEdit->setText(expressionLineEdit->text() + " " + mainLineEdit->text() + " =");

        if (currentOperation == DIVIDE) {
            if (secondValue > 0)
                mainLineEdit->setText(QString::number(firstValue / secondValue));
            else
                mainLineEdit->setText("Cannot divide by zero");
        }
        else if (currentOperation == MULTIPLICATION) {
            mainLineEdit->setText(QString::number(firstValue * secondValue));
        }
        else if (currentOperation == DIFFERENCE) {
            mainLineEdit->setText(QString::number(firstValue - secondValue));
        }
        else if (currentOperation == SUM) {
            mainLineEdit->setText(QString::number(firstValue + secondValue));
        }
        currentOperation = NONE;
    }

    void dot() {
        QString temp = mainLineEdit->text();
        if (temp.indexOf('.') == -1 && !temp.isEmpty()) {
            mainLineEdit->setText(mainLineEdit->text() + "." );
        }
    }

    void changeSign() {
        QString temp = mainLineEdit->text();
        if (checkValueForNull(temp)) return;
        if (temp[0] != '-') {
            mainLineEdit->setText("-" + mainLineEdit->text());
        }
        else {
            mainLineEdit->setText(temp.remove(0, 1));
        }
    }

private:
    double firstValue{};
    double secondValue{};
    operation currentOperation = NONE;

    static bool checkValueForNull (const QString& qString) {
        return qString.size() == 1 && qString[0] == '0';
    }

    void addNumber (const QChar& qChar) {
        if (mainLineEdit->text() == "0" || mainLineEdit->text() == "Cannot divide by zero") {
            mainLineEdit->setText(qChar);
        }
        else {
            mainLineEdit->setText(mainLineEdit->text() + qChar);
        }
    }

    static QString getQStringOperation (const operation& operation) {
        if (operation == DIVIDE)
            return " /";
        else if (operation == MULTIPLICATION)
            return " *";
        else if (operation == DIFFERENCE)
            return " -";
        else if (operation == SUM)
            return " +";
        else
            return " error";
    }

    void chooseOperation (const operation& operation) {
        if (currentOperation == NONE) {
            firstValue = mainLineEdit->text().toDouble();
            expressionLineEdit->setText(mainLineEdit->text() + getQStringOperation(operation));
            mainLineEdit->setText("0");
        }
        else {
            QString temp = expressionLineEdit->text();
            temp.resize(temp.size() - 2);
            expressionLineEdit->setText(temp + getQStringOperation(operation));
        }
        currentOperation = operation;
    }
};

#endif //INC_1_GRAPHING_CALCULATOR_CALCULATORMAINWINDOW_H

//
// Created by Alexander on 7/7/2022.
//

#include "CalculatorMainWindow.h"

void CalculatorMainWindow::add0() { addNumber('0'); }
void CalculatorMainWindow::add1() { addNumber('1'); }
void CalculatorMainWindow::add2() { addNumber('2'); }
void CalculatorMainWindow::add3() { addNumber('3'); }
void CalculatorMainWindow::add4() { addNumber('4'); }
void CalculatorMainWindow::add5() { addNumber('5'); }
void CalculatorMainWindow::add6() { addNumber('6'); }
void CalculatorMainWindow::add7() { addNumber('7'); }
void CalculatorMainWindow::add8() { addNumber('8'); }
void CalculatorMainWindow::add9() { addNumber('9'); }

void CalculatorMainWindow::clearExpression() {
    expressionLineEdit->clear();
    mainLineEdit->setText("0");
    currentOperation = NONE;
}

void CalculatorMainWindow::eraseCharacter()  {
    QString temp = mainLineEdit->text();
    if (temp.size() > 1) {
        temp.resize(temp.size() - 1);
        mainLineEdit->setText(temp);
    }
    else {
        mainLineEdit->setText("0");
    }
}

void CalculatorMainWindow::divide()         { chooseOperation(DIVIDE); }
void CalculatorMainWindow::multiplication() { chooseOperation(MULTIPLICATION); }
void CalculatorMainWindow::difference()     { chooseOperation(DIFFERENCE); }
void CalculatorMainWindow::sum()            { chooseOperation(SUM); }

void CalculatorMainWindow::getResult() {
    if (currentOperation == NONE) return;

    bool castToDoubleIsOk = false;
    secondValue = mainLineEdit->text().toDouble( &castToDoubleIsOk);

    if (castToDoubleIsOk) {
        expressionLineEdit->setText(expressionLineEdit->text() + " " + mainLineEdit->text() + " =");

        if (currentOperation == DIVIDE) {
            if (secondValue > 0)
                mainLineEdit->setText(QString::number(firstValue / secondValue, 'f', 3));
            else
                mainLineEdit->setText("Cannot divide by zero");
        }
        else if (currentOperation == MULTIPLICATION) {
            mainLineEdit->setText(QString::number(firstValue * secondValue, 'f', 3));
        }
        else if (currentOperation == DIFFERENCE) {
            mainLineEdit->setText(QString::number(firstValue - secondValue, 'f', 3));
        }
        else if (currentOperation == SUM) {
            mainLineEdit->setText(QString::number(firstValue + secondValue, 'f', 3));
        }
        currentOperation = NONE;
    }
    else {
        clearExpression();
        mainLineEdit->setText("Error");
    }
}

void CalculatorMainWindow::dot() {
    QString temp = mainLineEdit->text();
    if (temp.indexOf('.') == -1 && !temp.isEmpty()) {
        mainLineEdit->setText(mainLineEdit->text() + "." );
    }
}

void CalculatorMainWindow::changeSign() {
    QString temp = mainLineEdit->text();
    if (checkValueForNull(temp)) return;
    if (temp[0] != '-') {
        mainLineEdit->setText("-" + mainLineEdit->text());
    }
    else {
        mainLineEdit->setText(temp.remove(0, 1));
    }
}

bool CalculatorMainWindow::checkValueForNull(const QString &qString) {
    return qString.size() == 1 && qString[0] == '0';
}

QString CalculatorMainWindow::getQStringOperation (const operation& operation) {
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

void CalculatorMainWindow::addNumber (const QChar& qChar) const {
    if (mainLineEdit->text() == "0" || mainLineEdit->text() == "Cannot divide by zero" || mainLineEdit->text() == "Error") {
        mainLineEdit->setText(qChar);
    }
    else {
        mainLineEdit->setText(mainLineEdit->text() + qChar);
    }
}

void CalculatorMainWindow::chooseOperation (const operation& operation) {
    if (currentOperation == NONE) {
        bool castToDoubleIsOk = false;
        firstValue = mainLineEdit->text().toDouble( &castToDoubleIsOk);
        if (castToDoubleIsOk) {
            expressionLineEdit->setText(mainLineEdit->text() + getQStringOperation(operation));
            mainLineEdit->setText("0");
            currentOperation = operation;
        }
        else {
            mainLineEdit->setText("Error");
        }
    }
    else {
        QString temp = expressionLineEdit->text();
        temp.resize(temp.size() - 2);
        expressionLineEdit->setText(temp + getQStringOperation(operation));
        currentOperation = operation;
    }
}
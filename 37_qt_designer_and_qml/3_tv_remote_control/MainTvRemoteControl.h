//
// Created by Alexander on 7/14/2022.
//

#ifndef INC_3_TV_REMOTE_CONTROL_MAINTVREMOTECONTROL_H
#define INC_3_TV_REMOTE_CONTROL_MAINTVREMOTECONTROL_H

#include <iostream>
#include <QMainWindow>
#include <QtWidgets/QLabel>

class MainTvRemoteControl : public QMainWindow {
    Q_OBJECT

public:
    QLabel* label = nullptr;

    explicit MainTvRemoteControl(QWidget* parent = nullptr) : QMainWindow(parent) {}

public slots:
    void buttonPressed0();
    void buttonPressed1();
    void buttonPressed2();
    void buttonPressed3();
    void buttonPressed4();
    void buttonPressed5();
    void buttonPressed6();
    void buttonPressed7();
    void buttonPressed8();
    void buttonPressed9();
    void upVolume();
    void downVolume();
    void nextChannel();
    void previousChannel();
    void power();
    void accept();

private:
    bool powerIsOn = false;
    int currentChannel = 1;
    int volume = 100;
    QString inputChannel;

    void printInfo () const;
    void inputNumber (const QString& number);
};

#endif //INC_3_TV_REMOTE_CONTROL_MAINTVREMOTECONTROL_H

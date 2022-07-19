//
// Created by Alexander on 7/14/2022.
//

#include "MainTvRemoteControl.h"

void MainTvRemoteControl::buttonPressed0() { inputNumber("0"); }
void MainTvRemoteControl::buttonPressed1() { inputNumber("1"); }
void MainTvRemoteControl::buttonPressed2() { inputNumber("2"); }
void MainTvRemoteControl::buttonPressed3() { inputNumber("3"); }
void MainTvRemoteControl::buttonPressed4() { inputNumber("4"); }
void MainTvRemoteControl::buttonPressed5() { inputNumber("5"); }
void MainTvRemoteControl::buttonPressed6() { inputNumber("6"); }
void MainTvRemoteControl::buttonPressed7() { inputNumber("7"); }
void MainTvRemoteControl::buttonPressed8() { inputNumber("8"); }
void MainTvRemoteControl::buttonPressed9() { inputNumber("9"); }

void MainTvRemoteControl::upVolume() {
    if (powerIsOn && volume < 100) {
        volume += 10;
        printInfo();
    }
}

void MainTvRemoteControl::downVolume() {
    if (powerIsOn && volume > 0) {
        volume -= 10;
        printInfo();
    }
}

void MainTvRemoteControl::nextChannel() {
    if (powerIsOn && currentChannel < 500) {
        ++currentChannel;
        inputChannel.clear();
        printInfo();
    }
    else if (powerIsOn && currentChannel == 500) {
        currentChannel = 1;
        inputChannel.clear();
        printInfo();
    }
}

void MainTvRemoteControl::previousChannel() {
    if (powerIsOn && currentChannel > 1) {
        --currentChannel;
        printInfo();
    }
    else if (powerIsOn && currentChannel == 1) {
        currentChannel = 500;
        printInfo();
    }
}

void MainTvRemoteControl::power() {
    if (powerIsOn) {
        powerIsOn = false;
        label->clear();
    }
    else {
        powerIsOn = true;
        printInfo();
    };
}

void MainTvRemoteControl::accept() {
    if (powerIsOn && !inputChannel.isEmpty()) {
        currentChannel = inputChannel.toInt();
        inputChannel.clear();
        printInfo();
    }
}

void MainTvRemoteControl::printInfo() const {
    if (inputChannel.isEmpty()) {
        label->setText("Volume: " + QString::number(volume) + "%\nChannel: " + QString::number(currentChannel));
    }
    else {
        label->setText(inputChannel + "\nVolume: " + QString::number(volume) + "%\nChannel: " + QString::number(currentChannel));
    }
}

void MainTvRemoteControl::inputNumber(const QString &number) {
    if (powerIsOn) {
        inputChannel += number;
        if (inputChannel.toInt() > 500) {
            inputChannel = "500";
        }
        else if (inputChannel.toInt() < 1) {
            inputChannel = "1";
        }
        printInfo();
    }
}








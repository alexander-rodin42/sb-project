//
// Created by Alexander on 7/26/2022.
//

#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

#include "ImageButton.h"

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("C:\\Users\\Alexander\\Desktop\\sb-project\\38_advanced_qt\\1_adding_sound_to_a_button\\button_up.png");
    mButtonDownPixmap = QPixmap("C:\\Users\\Alexander\\Desktop\\sb-project\\38_advanced_qt\\1_adding_sound_to_a_button\\button_down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    buttonSound.setMedia(QUrl::fromLocalFile("C:\\Users\\Alexander\\Desktop\\sb-project\\38_advanced_qt\\1_adding_sound_to_a_button\\button_sound.mp3"));

    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.drawTiledPixmap(event->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *event) {
    setDown();
}

void ImageButton::setUp() {
    buttonSound.stop();
    buttonSound.play();

    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

void ImageButton::setDown() {
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

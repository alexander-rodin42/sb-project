//
// Created by Alexander on 7/26/2022.
//

#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>

#include "ImageButton.h"

ImageButton::ImageButton(QWidget *parent, const QString& folderPath) {
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap(folderPath + "\\button_up.png");
    mButtonDownPixmap = QPixmap(folderPath + "\\button_down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    buttonSound.setMedia(QUrl::fromLocalFile(folderPath + "\\button_sound.mp3"));

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

//
// Created by Alexander on 7/26/2022.
//

#pragma once

#include <QPushButton>
#include <QPixmap>
#include <QMediaPlayer>

class ImageButton : public QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent, const QString& folderPath = "C:\\Users\\");
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonUpPixmap;
    QPixmap mButtonDownPixmap;
    QMediaPlayer buttonSound;
};



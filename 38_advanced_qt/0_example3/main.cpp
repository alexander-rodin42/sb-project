#include <QtGui/QtGui>
#include <QApplication>

#include <QMediaPlayer>
#include <QMediaContent>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QFileDialog>

#include <QVideoWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget playerWindow;
    QVBoxLayout vbox(&playerWindow);
    QHBoxLayout buttons;

    auto* player = new QMediaPlayer(&playerWindow);
    auto* video = new QVideoWidget(&playerWindow); //video

    auto* songSlider = new QSlider(&playerWindow);
    songSlider->setOrientation(Qt::Horizontal);
    vbox.addWidget(video); //video
    vbox.addWidget(songSlider);

    auto* openFileButton = new QPushButton("Open", &playerWindow);
    auto* playMediaButton = new QPushButton("Play", &playerWindow);
    auto* pauseMediaButton = new QPushButton("Pause", &playerWindow);

    buttons.addWidget(openFileButton);
    buttons.addWidget(playMediaButton);
    buttons.addWidget(pauseMediaButton);

    vbox.addLayout(&buttons);

    QString filePath;
    bool isPlaying = false;

    //video
    player->setVideoOutput(video);

    QObject::connect(openFileButton, &QPushButton::clicked, [&filePath, player, &isPlaying](){
        filePath = QFileDialog::getOpenFileName(nullptr,
                                         "Open file",
                                            "C:\\Users\\",
                                           "media files (* mp3, * mp4)");

        player->stop();
        isPlaying = false;
    });

    QObject::connect(playMediaButton, &QPushButton::clicked, [&isPlaying, songSlider, player, &filePath](){
        if (!isPlaying) {
            player->setMedia(QUrl::fromLocalFile(filePath));
            player->setVolume(75);

            QObject::connect(player, &QMediaPlayer::durationChanged, [songSlider](qint64 duration){
                songSlider->setMinimum(0);
                songSlider->setMaximum(duration);
            });

            QObject::connect(player, &QMediaPlayer::positionChanged, [songSlider](qint64 pos){
                songSlider->setValue(pos);
            });
            isPlaying = true;
        }

        player->play();
    });

    QObject::connect(songSlider, &QSlider::valueChanged, player, &QMediaPlayer::setPosition);
    QObject::connect(pauseMediaButton, &QPushButton::clicked, player, &QMediaPlayer::pause);

    playerWindow.show();
    return app.exec();
}

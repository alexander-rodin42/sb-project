#include <QApplication>
#include <QMediaPlayer>

#include "ImageButton.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    ImageButton imageButton(&window);
    QMediaPlayer player(&window);

    player.setMedia(QUrl::fromLocalFile("C:\\Users\\Alexander\\Desktop\\sb-project\\38_advanced_qt\\1_adding_sound_to_a_button\\button_sound.mp3"));

    QObject::connect(&imageButton, &QPushButton::clicked, [&player](){
        player.play();
    });

    window.setFixedSize(150, 150);
    window.show();
    return QApplication::exec();
}

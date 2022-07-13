import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtMultimedia 5.15
import QtQuick.Layouts 1.15

RowLayout{
    id: loRow
    spacing: defMargin
    Layout.alignment: Qt.AlignHCenter
    Layout.fillWidth: true

    MyButton {
        id: play
        text: "▶️"
        onClicked: { video.play() }
    }

    MyButton {
        id: pause
        text: "⏸️"
        onClicked: { video.pause() }
    }

    MyButton {
        id: stop
        text: "⏹"
        onClicked: { video.stop() }
    }

    MyButton {
        id: back
        text: "⏪️"
        onClicked: { video.seek(video.position - video.duration / 20) }
    }

    MyButton {
        id: forward
        text: "⏩️"
        onClicked: { video.seek(video.position + video.duration / 20) }
    }
}

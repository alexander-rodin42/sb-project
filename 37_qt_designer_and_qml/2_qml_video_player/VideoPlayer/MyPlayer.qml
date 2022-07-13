import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtMultimedia 5.15
import QtQuick.Layouts 1.15

Rectangle {
    id: player
    Layout.alignment: Qt.AlignHCenter
    Layout.fillWidth: true
    Layout.fillHeight: true
    width: 640
    height: 480
    color: "black"

    property bool isPlaying: false

    Video {
        id: video
        anchors.fill: parent
        source: "C://Users//Alexander//Desktop//sb-project//37_qt_designer_and_qml//2_qml_video_player//VideoPlayer//video.mp4"

    }

    MouseArea {
        anchors.fill: parent
        onPressed: {
            if (isPlaying) {
                video.pause();
                isPlaying: false;
            }
            else {
                video.play();
                isPlaying: true;
            }
        }
        Text {
            anchors.centerIn: parent
            font.pointSize: 16
            text: isPlaying
            color: "red"
        }
    }
}

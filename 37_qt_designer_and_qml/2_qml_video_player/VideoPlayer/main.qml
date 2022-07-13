import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtMultimedia 5.15
import QtQuick.Layouts 1.15



Window {
    visible: true
    title: qsTr("VideoPlayer")

    property int defMargin: 4

    minimumWidth: loColumn.implicitWidth + defMargin
    minimumHeight: loColumn.implicitHeight + defMargin

    ColumnLayout {
        id: loColumn
        spacing: defMargin
        anchors.fill: parent
        anchors.margins: 2

        Rectangle {
            id: player
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
            width: 640
            height: 480
            color: "black"

            Video {
                id: video
                anchors.fill: parent
                source: textInput.text
            }

            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onPressed: { video.play() }
            }
        }

        MySlider {
        }

        MyLoRow {
        }

        TextInput {
            id: textInput
            Layout.fillWidth: true
            text: "E://Video//video.mp4"
        }
    }
//    MyLayoutBorder {
//    }
}

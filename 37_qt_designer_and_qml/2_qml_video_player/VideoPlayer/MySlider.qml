import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtMultimedia 5.15
import QtQuick.Layouts 1.15

Slider {
    id: control
    value: video.position / video.duration
    Layout.alignment: Qt.AlignHCenter
    Layout.fillWidth: true

    onPressedChanged: { video.seek(control.value * video.duration) }

    background: Rectangle {
        x: control.leftPadding
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 640
        implicitHeight: 4
        width: control.availableWidth
        height: implicitHeight
        radius: 2
        color: "#bdbebf"

        Rectangle {
            width: control.visualPosition * parent.width
            height: parent.height
            color: "#21be2b"
            radius: 2
        }
    }

    handle: Rectangle {
        x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
        y: control.topPadding + control.availableHeight / 2 - height / 2
        implicitWidth: 13
        implicitHeight: 26
        radius: 13
        color: control.pressed ? "#f0f0f0" : "#f6f6f6"
        border.color: "#bdbebf"
    }

    Text {
        id: plaingTime
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        text:  video.position / 1000 + " sec. / " +  video.duration / 1000 + " sec."
        font.pointSize: 6
        color: "black"
    }
}

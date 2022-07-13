import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12
import QtMultimedia 5.15
import QtQuick.Layouts 1.15

Rectangle {
    id: layoutBorder
    anchors.fill: loColumn
    border.width: 4
    border.color: "black"
    color: "transparent"
    Text {
        anchors.centerIn: parent
        font.pointSize: 16
        text: "Width: " + loColumn.width + "\nHeight: " + loColumn.height
        color: "red"
    }
}

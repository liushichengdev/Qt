import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3
import QtQuick.Layouts 6.3
import QtDataVisualization 6.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("")

    TextArea {
        id: textArea
        x: 132
        y: 243
        width: 227
        height: 134
        transformOrigin: Item.TopLeft
        placeholderText: qsTr("Text Area")
    }

    Button {
        id: button
        x: 0
        y: 0
        width: 131
        height: 27
        text: qsTr("Button")
    }
}

import QtQuick 2.7

Rectangle {
    property alias title: txt_title.text
    property alias text: txt_status.text

    border.width: 1
    border.color: "gray"
    radius: 5

    BaseText {
        id: txt_title
        anchors {
            margins: 20
            horizontalCenter: parent.horizontalCenter
            top: parent.top
        }
    }

    BaseText {
        id: txt_status
        anchors.centerIn: parent
    }
}

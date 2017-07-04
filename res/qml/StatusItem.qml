import QtQuick 2.7
import StatusThreadController 1.0

BaseRectangle {
    readonly property var controller: StatusThreadController {
        onUpdated: {
            text = qsTr("Статус\n\n")
                    + written + qsTr("/")
                    + generated + qsTr(" записано, ")
                    + (generated - written) + qsTr(" в ожидании")
        }
    }
}

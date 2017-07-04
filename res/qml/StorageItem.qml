import QtQuick 2.7
import StorageThreadController 1.0

BaseRectangle {
    readonly property var controller: StorageThreadController {}
    text: qsTr("Хранилище данных")
}

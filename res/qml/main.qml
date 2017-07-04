import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 600
    height: 400
    title: " "

    GridLayout {
        anchors.fill: parent
        anchors.margins: 20
        columns: 3
        columnSpacing: 20
        rowSpacing: 20

        GeneratorItem {
            id: generator0
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Поток 1")
        }

        GeneratorItem {
            id: generator1
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Поток 2")
        }

        GeneratorItem {
            id: generator2
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Поток 3")
        }

        StatusItem {
            id: status
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            title: qsTr("Поток 4")
        }

        StorageItem {
            id: storage
            Layout.fillHeight: true
            Layout.fillWidth: true
            title: qsTr("Поток 5")
        }

        Button {
            id: btn
            Layout.fillWidth: true
            Layout.columnSpan: 3
            implicitHeight: 40
            text: qsTr("Прочитать все данные")
            onClicked: storage.controller.readAllAsync()
        }
    }

    Component.onCompleted: {
        // status & notifications
        generator0.controller.generated.connect(status.controller.generated)
        generator1.controller.generated.connect(status.controller.generated)
        generator2.controller.generated.connect(status.controller.generated)
        storage.controller.written.connect(status.controller.written)
        // writing data
        generator0.controller.generated.connect(storage.controller.write)
        generator1.controller.generated.connect(storage.controller.write)
        generator2.controller.generated.connect(storage.controller.write)
    }
}

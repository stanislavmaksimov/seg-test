import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.3
import GeneratorThreadController 1.0

BaseRectangle {
    readonly property var controller: GeneratorThreadController {
        id: _controller
    }

    Slider {
        id: slider
        minimumValue: 0
        maximumValue: 1000
        stepSize: 1
        value: 50
        width: parent.width - anchors.margins * 2
        anchors {
            margins: 20
            left: parent.left
            bottom: parent.bottom
            right: parent.rignt
        }
        onValueChanged: {
            text = qsTr("Генерация данных\n") + slider.value + qsTr(" в секунду")
            _controller.setFrequencyAsync(value)
        }
    }
}

import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls.Material 2.12
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.12








Window {
    visible: true
    width: 1280
    height: 720

    maximumHeight: height
    minimumHeight:height
    maximumWidth:width
    minimumWidth:width

    title: qsTr("Hello World")
    color: "#4c191919"

    Material.accent: Material.color(Material.DeepOrange)
    Material.foreground: "#FFFFFFFF"


    GaussianBlur {
        source: parent
        deviation: 71.2
        radius: 8
        _alphaOnly: true
        anchors.fill: parent
        transparentBorder: false
        samples: 16
    }


    Item {
        id: element2
        anchors.fill: parent


        Button {
            id: button
            x: 131
            y: 220
            text: qsTr("Button")
            highlighted: true
        }

        Slider {
            id: slider
            x: 277
            y: 251
            value: 0.5
        }

        Switch {
            id: element1
            x: 291
            y: 182
            text: qsTr("Switch")

            Material.accent: Material.color(Material.DeepOrange)
        }

        Text {
            id: element
            x: 194
            y: 93
            height: 12
            text: qsTr("Text")
            fontSizeMode: Text.FixedSize
            renderType: Text.NativeRendering
            font.pixelSize: 12
        }






    }

}





































/*##^## Designer {
    D{i:1;anchors_height:200;anchors_width:200;anchors_x:119;anchors_y:208}
}
 ##^##*/

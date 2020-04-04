import QtQuick 2.14
import QtQuick.Controls 2.14
import TableModel 0.1


ApplicationWindow {
    visible: true
    width: 200
    height: 100
    TableView {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        clip: true

        model: TableModel {}

        delegate: Rectangle {
            implicitWidth: 100
            implicitHeight: 50
            Text {
                text: display
            }
        }
    }
}

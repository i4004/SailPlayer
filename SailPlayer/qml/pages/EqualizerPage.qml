import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	allowedOrientations: Orientation.All

	SilicaFlickable
	{
		anchors.fill: parent
		contentHeight: column.height

		Column
		{
			id: column
			anchors.left: parent.left
			anchors.right: parent.right

			PageHeader { title: qsTr("Equalizer") }

			ComboBox
			{
				width: 480
				label: "Preset"

				menu: ContextMenu
				{
					MenuItem { text: "My preset 1" }
					MenuItem { text: "Rock" }
					MenuItem { text: "Pop" }
				}
			}

			Row
			{
				anchors.horizontalCenter: parent.horizontalCenter

				Button
				{
				   text: qsTr("Add preset")
				   onClicked: pageStack.push(Qt.resolvedUrl("AddPresetDialog.qml"));
				}

				Button
				{
				   text: qsTr("Rename preset")
				   onClicked: pageStack.push(Qt.resolvedUrl("RenamePresetDialog.qml"));
				}
			}
		}
	}
}

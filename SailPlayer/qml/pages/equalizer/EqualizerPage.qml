import QtQuick 2.0
import Sailfish.Silica 1.0
import "../../Util.js" as Util

Page
{
	allowedOrientations: Orientation.All

	SilicaFlickable
	{
		anchors.fill: parent

		Column
		{
			id: column

			anchors.left: parent.left
			anchors.right: parent.right

			PageHeader
			{
				id: head
				title: qsTr("Equalizer")
			}

			TextSwitch { text: "Equalizer is enabled" }

			ComboBox
			{
				id: presetsComboBox

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
				   text: qsTr("Edit bands")
				   onClicked: pageStack.push(Qt.resolvedUrl("EqualizerBandsPage.qml"));
				}
			}
		}

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("Delete Current Preset")
			}

			MenuItem
			{
				text: qsTr("Duplicate Current Preset")
				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../ManageTextItemDialog.qml"),
												{ inputName: qsTr("New Preset Name"), dialogTitle: qsTr("Duplicate Preset") });

					dialog.accepted.connect(function()
					{
					});
				}
			}

			MenuItem
			{
				text: qsTr("Edit Current Preset Name")
				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../ManageTextItemDialog.qml"),
												{ inputName: qsTr("Preset Name"), dialogTitle: qsTr("Edit Preset Name") });

					dialog.accepted.connect(function()
					{
					});
				}
			}

			MenuItem
			{
				text: qsTr("New Preset")
				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../ManageTextItemDialog.qml"),
												{ inputName: qsTr("Preset Name"), dialogTitle: qsTr("New Preset") });

					dialog.accepted.connect(function()
					{
					});
				}
			}
		}
	}
}

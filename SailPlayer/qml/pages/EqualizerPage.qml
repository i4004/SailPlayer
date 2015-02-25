import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Util.js" as Util

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

			TextSwitch
			{
				text: "Equalizer is enabled"
			}

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

			SilicaListView
			{
				id: listView
				anchors.left: parent.left
				anchors.right: parent.right
				height: 1000
//				anchors.top: column.bottom
//				anchors.bottom: parent.bottom

				model: ListModel
				{
					ListElement { gain: -5; frequency: 80 }
					ListElement { gain: 0; frequency: 160 }
					ListElement { gain: 5; frequency: 524 }
					ListElement { gain: 5; frequency: 1200 }
					ListElement { gain: 15; frequency: 6128 }
					ListElement { gain: 0; frequency: 11000 }
					ListElement { gain: -14; frequency: 14250 }
				}

				delegate: ListItem
				{
					contentHeight: gainSlider.height// + Theme.paddingLarge

					Label
					{
						id: frequencyLabel
						anchors.left: parent.left
						anchors.leftMargin: Theme.paddingLarge
						anchors.verticalCenter: parent.verticalCenter
						horizontalAlignment: Text.AlignRight
						width: 100

						text: Util.formatFequency(frequency)
					}

					Slider
					{
						id: gainSlider

						anchors.left: frequencyLabel.right
						anchors.right: clearButton.left
						anchors.leftMargin: -50
						anchors.rightMargin: -60
						anchors.verticalCenter: parent.verticalCenter

						maximumValue: 40
						value: gain + 20
						valueText: parseInt(value) - 20
					}

					IconButton
					{
						id: clearButton

						anchors.right: parent.right
						anchors.verticalCenter: parent.verticalCenter

						icon.source: "image://theme/icon-m-clear"
						onClicked: gainSlider.value = 20
					}
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
					var dialog = pageStack.push(Qt.resolvedUrl("ManageTextItemDialog.qml"),
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
					var dialog = pageStack.push(Qt.resolvedUrl("ManageTextItemDialog.qml"),
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
					var dialog = pageStack.push(Qt.resolvedUrl("ManageTextItemDialog.qml"),
												{ inputName: qsTr("Preset Name"), dialogTitle: qsTr("New Preset") });

					dialog.accepted.connect(function()
					{
					});
				}
			}
		}
	}
}

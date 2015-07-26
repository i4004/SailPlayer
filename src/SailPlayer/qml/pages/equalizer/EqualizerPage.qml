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

			PageHeader { title: qsTr("Equalizer") }

			SectionHeader { text: qsTr('General') }

			TextSwitch { text: "Equalizer is enabled" }

			SectionHeader { text: qsTr('Presets') }

			ComboBox
			{
				id: presetsComboBox

				label: "Preset"
				currentIndex: equalizerController.setSelectedPreset(settings.selectedEqualizerPresetIndex) ? settings.selectedEqualizerPresetIndex : 0

				menu: ContextMenu
				{
					Repeater
					{
						model: equalizerPresetsModel

						MenuItem
						{
							text: model.presetName
						}
					}
				}

				onCurrentItemChanged: equalizerController.setSelectedPreset(currentIndex);
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
				enabled: presetsComboBox.currentItem != null
				text: qsTr("Delete Current Preset")
				onClicked: equalizerController.deletePreset(presetsComboBox.currentIndex)
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
				enabled: presetsComboBox.currentItem != null
				text: qsTr("Edit Current Preset Name")
				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../ManageTextItemDialog.qml"),
												{ inputName: qsTr("Preset Name"), value: equalizerPresetsModel.getCurrentPresetName(), dialogTitle: qsTr("Edit Preset Name") });

					dialog.accepted.connect(function()
					{
						onClicked: equalizerController.setCurrentPresetName(dialog.value)
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
						equalizerController.addNewPreset(dialog.value);
						equalizerController.savePresets();
					});
				}
			}
		}
	}
}

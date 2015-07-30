import QtQuick 2.0
import Sailfish.Silica 1.0
import "../../Util.js" as Util

Dialog
{
	allowedOrientations: Orientation.All

	SilicaListView
	{
		id: listView

		anchors.fill: parent

		header: DialogHeader
		{
			id: dialogHeader

			title: qsTr("Equalizer: My preset 1")
			acceptText: qsTr("Ok")
		}

		model: equalizerModel

		delegate: ListItem
		{
			contentHeight: 90

			Label
			{
				id: frequencyLabel
				anchors.left: parent.left
				anchors.leftMargin: Theme.paddingLarge
				anchors.verticalCenter: parent.verticalCenter
				horizontalAlignment: Text.AlignRight
				width: 100

				text: Util.formatFequency(bandFrequency)
			}

			Slider
			{
				id: gainSlider

				anchors.left: frequencyLabel.right
				anchors.right: clearButton.left
				anchors.leftMargin: -25
				anchors.rightMargin: -30
				anchors.verticalCenter: parent.verticalCenter

				maximumValue: 36
				value: bandGain + 24
				valueText: parseInt(value) - 24
			}

			IconButton
			{
				id: clearButton

				anchors.right: parent.right
				anchors.verticalCenter: parent.verticalCenter

				icon.source: "image://theme/icon-m-clear"
				onClicked: gainSlider.value = 24
			}
		}

		VerticalScrollDecorator{}
	}
}

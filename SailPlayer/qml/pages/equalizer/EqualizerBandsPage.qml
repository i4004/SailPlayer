import QtQuick 2.0
import Sailfish.Silica 1.0
import "../../Util.js" as Util

Page
{
	allowedOrientations: Orientation.All

	SilicaListView
	{
		id: listView

		anchors.fill: parent

		header: PageHeader { title: qsTr("Equalizer: My preset 1") }

		model: ListModel
		{
			ListElement { gain: -5; frequency: 80 }
			ListElement { gain: 5; frequency: 524 }
			ListElement { gain: 0; frequency: 160 }
			ListElement { gain: 5; frequency: 524 }
			ListElement { gain: 5; frequency: 524 }
			ListElement { gain: 5; frequency: 524 }
			ListElement { gain: 5; frequency: 1200 }
			ListElement { gain: 5; frequency: 524 }
			ListElement { gain: 5; frequency: 1200 }
			ListElement { gain: 5; frequency: 524 }
			ListElement { gain: 5; frequency: 1200 }
			ListElement { gain: 15; frequency: 6128 }
			ListElement { gain: 5; frequency: 1200 }
			ListElement { gain: 0; frequency: 11000 }
			ListElement { gain: -14; frequency: 14250 }
			ListElement { gain: -14; frequency: 15000 }
			ListElement { gain: -14; frequency: 17000 }
		}

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

				text: Util.formatFequency(frequency)
			}

			Slider
			{
				id: gainSlider

				anchors.left: frequencyLabel.right
				anchors.right: clearButton.left
				anchors.leftMargin: -25
				anchors.rightMargin: -30
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

		VerticalScrollDecorator{}
	}
}

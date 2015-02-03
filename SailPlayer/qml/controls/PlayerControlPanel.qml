import QtQuick 2.0
import Sailfish.Silica 1.0

DockedPanel
{
	id: dockPanel

	width: parent.width
	height: playerControlsColumn.height + Theme.paddingLarge
	dock: Dock.Bottom

	property int progressMinValue: 0
	property int progressMaxValue: 0
	property int progressValue: 0
	property bool isPlayling: false

	anchors.left: parent.left
	anchors.right: parent.right

	Column
	{
		id: playerControlsColumn
		height: spacer.height + progressBar.height + playerButtons.height
		anchors.left: parent.left
		anchors.right: parent.right

		VerticalSpacerMedium { id: spacer }

		ProgressBar
		{
			id: progressBar
			anchors.left: parent.left
			anchors.right: parent.right
			maximumValue: 100
			minimumValue: 0
			value: 50
		}

		Row
		{
			id: playerButtons
			anchors.horizontalCenter: parent.horizontalCenter
			spacing: 35
			height: playIcon.height

			IconButton
			{
				icon.source: "image://theme/icon-m-previous"
			}

			IconButton
			{
				id: playIcon
				icon.source: isPlayling ? "image://theme/icon-m-pause" : "image://theme/icon-m-play"
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-tab"
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-next"
			}
		}
	}
}

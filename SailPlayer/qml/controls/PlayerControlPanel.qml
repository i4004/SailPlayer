import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Util.js" as Util

DockedPanel
{
	id: dockPanel

	property int progressMinValue: 0
	property int progressMaxValue: 0
	property int progressValue: 0
	property bool isPlaying: false

	signal previous
	signal playPause
	signal stop
	signal next
	signal positonChange

	width: parent.width
	height: playerControlsColumn.height + Theme.paddingLarge
	dock: Dock.Bottom

	anchors.left: parent.left
	anchors.right: parent.right

	Column
	{
		id: playerControlsColumn
		height: progressBar.height + playerButtons.height
		anchors.left: parent.left
		anchors.right: parent.right

		Slider
		{
			id: progressBar
			anchors.left: parent.left
			anchors.right: parent.right
			maximumValue: 700
			minimumValue: 0
			value: 356
			valueText: Util.formatTrackDuration(value)
		}

		Row
		{
			id: playerButtons
			anchors.horizontalCenter: parent.horizontalCenter
			spacing: 38
			height: playIcon.height

			IconButton
			{
				icon.source: "image://theme/icon-m-previous"
				onClicked: previous()
			}

			IconButton
			{
				id: playIcon
				icon.source: isPlaying ? "image://theme/icon-m-pause" : "image://theme/icon-m-play"
				onClicked: playPause()
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-tab"
				onClicked: stop()
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-next"
				onClicked: next()
			}
		}
	}
}

import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Util.js" as Util

DockedPanel
{
	id: dockPanel

	property bool isPlaying: false

	signal previous
	signal playPause
	signal stop
	signal next

	function setTrackDuration(value)
	{
		slider.maximumValue = value;
		slider.value = 0;
	}

	width: parent.width
	height: playerControlsColumn.height + Theme.paddingLarge
	dock: Dock.Bottom

	anchors.left: parent.left
	anchors.right: parent.right

	Column
	{
		id: playerControlsColumn
		height: slider.height + playerButtons.height
		anchors.left: parent.left
		anchors.right: parent.right

		Slider
		{
			id: slider
			maximumValue: 1
			anchors.left: parent.left
			anchors.right: parent.right
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
				onClicked:
				{
					isPlaying = !isPlaying;
					playPause();
				}
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-tab"
				onClicked:
				{
					isPlaying = false;
					stop();
				}
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-next"
				onClicked: next()
			}
		}
	}
}

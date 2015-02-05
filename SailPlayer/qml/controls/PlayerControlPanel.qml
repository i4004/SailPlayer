import QtQuick 2.0
import Sailfish.Silica 1.0
import "../Util.js" as Util

DockedPanel
{
	id: dockPanel

	signal previous
	signal playPause(bool isPlaying)
	signal stop(bool isPlaying)
	signal next

	function setTrackDuration(value)
	{
		slider.maximumValue = value;
		slider.value = 0;
	}

	function setCurrentTrackPosition(value)
	{
		slider.value = value;
	}

	function setIsPlaying(value)
	{
		playerButtons.isPlaying = value;
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

			property bool isPlaying: false

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
				icon.source: playerButtons.isPlaying ? "image://theme/icon-m-pause" : "image://theme/icon-m-play"
				onClicked:
				{
					playerButtons.isPlaying = !playerButtons.isPlaying;
					playPause(playerButtons.isPlaying);
				}
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-tab"
				onClicked:
				{
					playerButtons.isPlaying = false;
					stop(playerButtons.isPlaying);
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

import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayerState 1.0
import "../Util.js" as Util

DockedPanel
{
	id: dockPanel

	signal previous(int state)
	signal playPause(int state)
	signal stop(int state)
	signal next(int state)
	signal seek(int seconds)

	function setTrackDuration(value)
	{
		if(value === 0)
		{
			slider.enabled = false;
			slider.maximumValue = 1;
		}
		else
		{
			slider.enabled = true;
			slider.maximumValue = value;
		}
	}

	function setTrackPosition(value)
	{
		if(!slider.highlighted && !slider.seekRequestProcess)
			slider.value = value;
	}

	function onPlayerStateChanged(state)
	{
		playerButtons.currentPlayerState = state;
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
			property bool seekRequestProcess: false

			id: slider

			maximumValue: 1
			enabled: false

			anchors.left: parent.left
			anchors.right: parent.right
			valueText: Util.formatTrackDuration(value)
			onPressed: seekRequestProcess = true
			onReleased:
			{
				if(seekRequestProcess)
					seek(value);

				seekRequestProcess = false;
			}
		}

		Row
		{
			id: playerButtons

			property int currentPlayerState: AudioPlayerState.Ready

			anchors.horizontalCenter: parent.horizontalCenter
			spacing: 38
			height: playIcon.height

			IconButton
			{
				icon.source: "image://theme/icon-m-previous"
				onClicked: previous(playerButtons.currentPlayerState)
			}

			IconButton
			{
				id: playIcon
				icon.source: playerButtons.currentPlayerState === AudioPlayerState.Playing ? "image://theme/icon-m-pause" : "image://theme/icon-m-play"
				onClicked: playPause(playerButtons.currentPlayerState);
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-tab"
				onClicked:
				{
					stop(playerButtons.currentPlayerState);
					slider.value = 0;
				}
			}

			IconButton
			{
				icon.source: "image://theme/icon-m-next"
				onClicked: next(playerButtons.currentPlayerState)
			}
		}
	}
}

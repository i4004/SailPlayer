import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayerState 1.0

CoverBackground
{
	CoverPlaceholder
	{
		text: qsTrId("Sail Player")
		icon.source: "images/harbour-sail-player.png"
	}

	CoverActionList
	{
		CoverAction
		{
			iconSource: "image://theme/icon-cover-next-song"
			onTriggered: playController.next()
		}

		CoverAction
		{
			iconSource: player.state === AudioPlayerState.Playing ? "image://theme/icon-cover-pause" : "image://theme/icon-cover-play"
			onTriggered: playController.playPause()
		}
	}
}

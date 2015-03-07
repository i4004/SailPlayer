import QtQuick 2.0
import Sailfish.Silica 1.0
//import harbour.sail.player.AudioPlayerState 1.0
//import harbour.sail.player.PlayDirection 1.0

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
//			onTriggered:
//			{
//				player.stop();
//				if(playlist.calculateAndSetTrackToPlay(PlayDirection.NextWithForce))
//					player.play();
//			}
		}

		CoverAction
		{
			iconSource: /*player.state === AudioPlayerState.Playing ? "image://theme/icon-cover-pause" :*/ "image://theme/icon-cover-play"
//			onTriggered:
//			{
//				if(player.state === AudioPlayerState.Playing)
//					player.pause();
//				else
//				{
//					if(player.state === AudioPlayerState.Ready && !playlist.hasTrackToPlay())
//						playlist.calculateAndSetTrackToPlay();

//					if(player.hasTrackToPlay())
//						player.play();
//				}
//			}
		}
	}
}

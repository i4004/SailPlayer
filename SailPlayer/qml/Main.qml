import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"
import "controls"

ApplicationWindow
{
	Component.onCompleted: player.PlaybackError.connect(messagePage.displayMessage);

//	Timer
//	{
//		id: elapseTimer

//		property var startTime
//		property int elapsed: 0

//		interval: 1000;
//		running: false;
//		repeat: true

//		onTriggered:
//		{
//			elapsed++;

//			// If track duration is more than 5 seconds and is played more than half of track length or more than 4 minutes
//			if(!scrobbler.scrobbled && player.currentDuration > 5000 && elapsed * 1000 >= player.currentDuration / 2 || elapsed >= 2401000)
//			{
//				scrobbler.scrobbled = true;
//				scrobbler.scrobbleTrack(playlist.getCurrentPlayingTrack(), startTime);
//			}
//		}
//	}


//		property bool scrobbled: false

//		Component.onCompleted: loadSavedTracksToCache()
//		Component.onDestruction: saveCachedTracks()

	MessagePageDisplayer
	{
		id: messagePage
		title: qsTr("Playback error")
	}

//	NotificationPanel
//	{
//		id: notifiicationPanel
//	}

	initialPage: Component { MainPage {} }
	cover: Qt.resolvedUrl("Cover.qml")
}

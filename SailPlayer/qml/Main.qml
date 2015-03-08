import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"

ApplicationWindow
{
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

//	LastFmScrobbler
//	{
//		id: scrobbler

//		property bool scrobbled: false

//		apiKey: "06b931aaed5fbf1f1558c165f3a08eb4"
//		secret: "9fe3f69ecd90045d2d18fe6823803370"
//		sessionKey: settings.lastFmSessionKey

//		Component.onCompleted: loadSavedTracksToCache()
//		Component.onDestruction: saveCachedTracks()
//	}

//	MessagePageDisplayer
//	{
//		id: messagePage
//		title: qsTr("Playback error")
//	}

//	NotificationPanel
//	{
//		id: notifiicationPanel
//	}

	initialPage: Component { MainPage {} }
	cover: Qt.resolvedUrl("Cover.qml")
}

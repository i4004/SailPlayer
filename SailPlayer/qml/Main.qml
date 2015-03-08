import QtQuick 2.0
import Sailfish.Silica 1.0
//import harbour.sail.player.AudioPlayer 1.0
//import harbour.sail.player.AudioPlayerState 1.0
//import harbour.sail.player.PlayDirection 1.0
//import harbour.sail.player.SailPlayerSettings 1.0
//import harbour.sail.player.LastFmScrobbler 1.0
//import harbour.sail.player.LastFmError 1.0
import "pages"
//import "controls"

ApplicationWindow
{
//	AudioPlayer
//	{
//		id: player

//		property bool needToSetStartupPosition: false
//		property bool needToSetStartupTrackLastFmNowPlaying: false

//		onStreamStarted:
//		{
//			if(needToSetStartupPosition)
//			{
//				needToSetStartupPosition = false;

//				if(settings.lastPlayingPosition !== -1)
//					seek(settings.lastPlayingPosition);

//				needToSetStartupTrackLastFmNowPlaying = true;
//			}

//			if(player.isStreamFromNextTrack() && !playlist.setTrackToPlayAndPlayingFromNextTrack())
//				player.stop();
//			else if(!needToSetStartupTrackLastFmNowPlaying && settings.scrobblingIsEnabled)
//				startScrobbleMotitoring();
//		}

//		onAboutToFinish: player.setNextTrackToPlay(playlist.requestNextTrack(), playlist.getNextStartPosition(), playlist.getNextEndPosition())

//		onEndOfStream: player.stop()

//		onStateChanged:
//		{
//			if(state == AudioPlayerState.Ready)
//				needToSetStartupTrackLastFmNowPlaying = false;

//			if(state == AudioPlayerState.Playing)
//			{
//				if(settings.scrobblingIsEnabled)
//				{
//					if(needToSetStartupTrackLastFmNowPlaying)
//					{
//						needToSetStartupTrackLastFmNowPlaying = false;
//						startScrobbleMotitoring();
//					}

//					elapseTimer.start();
//				}
//			}
//			else
//				elapseTimer.stop();
//		}

//		function startScrobbleMotitoring()
//		{
//			elapseTimer.startTime = new Date();
//			scrobbler.sendNowPlaying(playlist.getCurrentPlayingTrack());
//			elapseTimer.elapsed = 0;
//			scrobbler.scrobbled = false;
//		}
//	}

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

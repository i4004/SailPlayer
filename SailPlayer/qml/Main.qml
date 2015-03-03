import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.AudioPlayerState 1.0
import harbour.sail.player.PlaylistModel 1.0
import harbour.sail.player.PlayDirection 1.0
import harbour.sail.player.PlayOrder 1.0
import harbour.sail.player.SailPlayerSettings 1.0
import harbour.sail.player.LastFmScrobbler 1.0
import harbour.sail.player.LastFmError 1.0
import "pages"
import "controls"

ApplicationWindow
{
	id: applicationWindow

	AudioPlayer
	{
		id: player

		property bool needToSetStartupPosition: false
		property bool needToSetStartupTrackLastFmNowPlaying: false
		property var trackPlayStartTime
		property int elapsed: 0
		property bool scrobbled: false

		onStreamStarted:
		{
			if(needToSetStartupPosition)
			{
				needToSetStartupPosition = false;

				if(settings.currentPlayingPosition !== -1)
					seek(settings.currentPlayingPosition);

				needToSetStartupTrackLastFmNowPlaying = true;
			}

			if(player.isStreamFromNextTrack() && !playlist.setTrackToPlayAndPlayingFromNextTrack())
				player.stop();
			else if(!needToSetStartupTrackLastFmNowPlaying && settings.scrobblingIsEnabled)
			{
				trackPlayStartTime = new Date();

				scrobbler.sendNowPlaying(playlist.getCurrentPlayingTrack());
				elapsed = 0;
				scrobbled = false;
			}
		}

		onAboutToFinish: player.setNextTrackToPlay(playlist.requestNextTrack(), playlist.getNextStartPosition(), playlist.getNextEndPosition())

		onEndOfStream: player.stop()

		onStateChanged:
		{
			if(state == AudioPlayerState.Ready)
				needToSetStartupTrackLastFmNowPlaying = false;

			if(state == AudioPlayerState.Playing)
			{
				if(needToSetStartupTrackLastFmNowPlaying && settings.scrobblingIsEnabled)
				{
					needToSetStartupTrackLastFmNowPlaying = false;
					trackPlayStartTime = new Date();
					scrobbler.sendNowPlaying(playlist.getCurrentPlayingTrack());
					elapsed = 0;
					scrobbled = false;
				}

				elapseTimer.start();
			}
			else
				elapseTimer.stop();
		}

		Component.onCompleted:
		{
			playlist.currentTrackToPlayDataUpdated.connect(player.setTrackToPlay);
			player.stateChanged.connect(playlist.setPlayerState);
			player.playbackError.connect(messagePage.displayMessage);

			playlist.loadPlaylist();

			if(settings.restoreLastPlayingPosition && settings.currentTrackIndex !== -1)
			{
				needToSetStartupPosition = true;
				playlist.calculateAndSetTrackToPlay(PlayDirection.ByIndex, settings.currentTrackIndex);
				player.pause();
			}
		}

		Component.onDestruction:
		{
			if(player.state === AudioPlayerState.Playing)
				player.pause();

			playlist.savePlaylist();
			settings.currentTrackIndex = playlist.getCurrentTrackIndex();
			settings.currentPlayingPosition = player.getCurrentPosition();
		}
	}

	Timer
	{
		id: elapseTimer

		interval: 1000;
		running: false;
		repeat: true

		onTriggered:
		{
			player.elapsed++;

			// If track duration is more than 5 seconds and is played more than half of track length or more than 4 minutes
			if(!player.scrobbled && player.currentDuration > 5000 && player.elapsed * 1000 >= player.currentDuration / 2 || player.elapsed >= 2401000)
			{
				player.scrobbled = true;
				scrobbler.scrobbleTrack(playlist.getCurrentPlayingTrack(), player.trackPlayStartTime);
			}
		}
	}

	PlaylistModel
	{
		id: playlist

		Component.onCompleted: playOrder = settings.currentPlayOrder
		Component.onDestruction: settings.currentPlayOrder = playlist.playOrder
	}

	SailPlayerSettings { id: settings }

	LastFmScrobbler
	{
		id: scrobbler

		apiKey: "06b931aaed5fbf1f1558c165f3a08eb4"
		secret: "9fe3f69ecd90045d2d18fe6823803370"
		sessionKey: settings.lastFmSessionKey

		Component.onCompleted:
		{
			errorResponse.connect(onError);
			loadSavedTracksToCache();
		}

		Component.onDestruction: saveCachedTracks()

		function onError(error, description)
		{
			if(error === LastFmError.AuthenticationFailed)
				notifiicationPanel.showText(qsTr('Invalid user name or password.'));
			else if(error === LastFmError.NoInternetConnection)
				notifiicationPanel.showText(qsTr('No internet connection.'));
			else
				notifiicationPanel.showText(description);
		}
	}

	MessagePageDisplayer
	{
		id: messagePage
		title: qsTr("Playback error")
	}

	NotificationPanel
	{
		id: notifiicationPanel
	}

	initialPage: Component { MainPage {} }
	cover: Qt.resolvedUrl("Cover.qml")
}

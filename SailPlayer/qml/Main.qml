import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.AudioPlayerState 1.0
import harbour.sail.player.PlaylistModel 1.0
import harbour.sail.player.PlayDirection 1.0
import harbour.sail.player.PlayOrder 1.0
import harbour.sail.player.SailPlayerSettings 1.0
import harbour.sail.player.LastFmScrobbler 1.0
import "pages"
import "controls"

ApplicationWindow
{
	id: applicationWindow

	AudioPlayer
	{
		id: player

		property bool needToSetStartupPosition: false

		onStreamStarted:
		{
			if(needToSetStartupPosition)
			{
				needToSetStartupPosition = false;

				if(settings.currentPlayingPosition !== -1)
					seek(settings.currentPlayingPosition);
			}

			if(player.isStreamFromNextTrack() && !playlist.setTrackToPlayAndPlayingFromNextTrack())
				player.stop();
		}

		onAboutToFinish: player.setNextTrackToPlay(playlist.requestNextTrack(), playlist.getNextStartPosition(), playlist.getNextEndPosition())

		onEndOfStream: player.stop()

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
	}

	MessagePageDisplayer
	{
		id: messagePage
		title: qsTr("Playback error")
	}

	initialPage: Component { MainPage {} }
	cover: Qt.resolvedUrl("Cover.qml")
}

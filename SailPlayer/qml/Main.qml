import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.AudioPlayerState 1.0
import harbour.sail.player.PlaylistModel 1.0
import harbour.sail.player.PlayDirection 1.0
import harbour.sail.player.PlayOrder 1.0
import "pages"

ApplicationWindow
{
	id: applicationWindow

	AudioPlayer
	{
		id: player

		onStreamStarted:
		{
			if(needToSetStartupPosition)
			{
				needToSetStartupPosition = false;

				var currentPosition = playlist.loadCurrentPosition();

				if(currentPosition !== -1)
					seek(currentPosition);
			}

			if(player.isStreamFromNextTrack() && !playlist.setTrackToPlayAndPlayingFromNextTrack())
				player.stop();
		}

		onAboutToFinish:
		{
			var path = playlist.requestNextTrack();
			var startPosition = playlist.getNextStartPosition();
			var endPosition = playlist.getNextEndPosition();

			player.setNextTrackToPlay(path, startPosition, endPosition);
		}

		onEndOfStream: player.stop()

		Component.onCompleted:
		{
			playlist.currentTrackToPlayDataUpdated.connect(player.setTrackToPlay);
			player.stateChanged.connect(playlist.setPlayerState);
			player.playbackError.connect(applicationWindow.onPlaybackError);

			playlist.loadPlaylist();

			var currentTrackIndex = playlist.loadCurrentTrackIndex();

			if(currentTrackIndex !== -1)
			{
				needToSetStartupPosition = true;
				playlist.calculateAndSetTrackToPlay(PlayDirection.ByIndex, currentTrackIndex);
				player.pause();
			}
		}

		Component.onDestruction:
		{
			if(player.getCurrentState() === AudioPlayerState.Playing)
				player.pause();

			playlist.savePlaylist();
			playlist.saveCurrentPlayingState(playlist.getCurrentTrackIndex(), player.getCurrentPosition());
		}
	}

	property bool needToSetStartupPosition: false
	property var playbackErrorPage

	function onPlaybackError(value)
	{
		if(playbackErrorPage !== null && pageStack.currentPage === playbackErrorPage)
			return;

		playbackErrorPage = pageStack.push(Qt.resolvedUrl("pages/PlaybackErrorInfoPage.qml"), { message: value });
	}

	PlaylistModel { id: playlist }

	initialPage: Component { DefaultPage {} }
	cover: Qt.resolvedUrl("Cover.qml")
}

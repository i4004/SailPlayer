import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.AudioPlayerState 1.0
import harbour.sail.player.PlaylistModel 1.0
import harbour.sail.player.PlayDirection 1.0
import harbour.sail.player.PlayOrder 1.0
import "../controls"
import "../Util.js" as Util

Page
{
	id: page

	AudioPlayer
	{
		id: player

		onEndOfStreamReached:
		{
			player.stop();

			if(playlist.calculateTrackToPlay())
				player.play();
		}
	}

	allowedOrientations: Orientation.All

	Component.onCompleted:
	{
		playlist.currentTrackFilePathUpdated.connect(player.setFileToPlay);
		player.currentDurationUpdated.connect(playerControlPanel.setTrackDuration);
		player.currentPositionUpdated.connect(playerControlPanel.setTrackPosition);
		player.stateChanged.connect(playerControlPanel.onPlayerStateChanged);
		player.stateChanged.connect(playlist.playerStateChanged);

		playlist.loadPlaylist();
		playlist.calculateTrackToPlay();
		playOrderControl.setOrder(playlist.playOrder);
	}

	Component.onDestruction:
	{
		playlist.savePlaylist();
		player.stateChanged.disconnect(playerControlPanel.onPlayerStateChanged);
		player.currentDurationUpdated.disconnect(playerControlPanel.setTrackDuration);
		player.currentPositionUpdated.disconnect(playerControlPanel.setTrackPosition);
	}

	SilicaListView
	{
		id: listView

		anchors.fill: parent
		anchors.bottomMargin: playerControlPanel.visible ? playerControlPanel.visibleSize : 0
		header: PageHeader { title: "Default Playlist" }

		clip: true

		model: PlaylistModel { id: playlist }

		delegate: PlaylistItem
		{
			onClicked:
			{
				playerControlPanel.show();
				playlist.toggleSelectTrack(index);
			}

			onPushAndHold:
			{
				player.stop();

				if(playlist.calculateTrackToPlay(PlayDirection.ByIndex, index))
					player.play();
			}
		}

		section
		{
			property: "section"
			delegate: PlaylistSectionHeader {}
		}

		VerticalScrollDecorator {}

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("About")
				onClicked: pageStack.push(Qt.resolvedUrl("../pages/About.qml"))
			}

			MenuItem
			{
				text: qsTr("Settings")
				onClicked: pageStack.push(Qt.resolvedUrl("../pages/Settings.qml"))
			}

			MenuItem
			{
				text: qsTr("Add Folder")

				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../pages/AddFilesDialog.qml"));

					dialog.accepted.connect(function()
					{
						playlist.addTracks(dialog.directoryPath);
					});
				}
			}
		}

		RemorsePopup
		{
			id: remorse
		}

		PushUpMenu
		{
			Column
			{
				width: parent.width

				MenuItem
				{
					text: qsTr("Clear Playlist")
					onClicked: remorse.execute(qsTr("Clearing"), function() { playlist.clearPlaylist() })
				}

				PlayOrderControl
				{
					id: playOrderControl
					onOrderChange: playlist.playOrder = order
				}
			}
		}
	}

	PlayerControlPanel
	{
		id: playerControlPanel

		onPrevious:
		{
			player.stop();
			if(playlist.calculateTrackToPlay(PlayDirection.Previous) && state != AudioPlayerState.Ready)
				player.play();
		}

		onPlayPause:
		{
			if(state == AudioPlayerState.Playing)
				player.pause();
			else
			{
				if(state == AudioPlayerState.Ready && !playlist.hasTrackToPlay())
					playlist.calculateTrackToPlay();

				if(player.hasFileToPlay())
					player.play();
			}
		}

		onStop: player.stop()
		onSeek: player.seek(seconds)
		onNext:
		{
			player.stop();
			if(playlist.calculateTrackToPlay(PlayDirection.NextWithForce) && state != AudioPlayerState.Ready)
				player.play();
		}
	}
}

import QtQuick 2.0
import Sailfish.Silica 1.0
//import harbour.sail.player.FsHelper 1.0
//import harbour.sail.player.AudioPlayerState 1.0
//import harbour.sail.player.PlayDirection 1.0
//import "../controls"
//import "../controls/playlist"

Page
{
	id: page

	allowedOrientations: Orientation.All

//	FsHelper{ id: fsHelper }

	SilicaListView
	{
		id: listView

		anchors.fill: parent
//		anchors.bottomMargin: playerControlPanel.visible ? playerControlPanel.visibleSize : 0
		clip: true

		header: PageHeader { title: "Default Playlist" }

//		model: playlist

		ViewPlaceholder
		{
			enabled: listView.count == 0
			text: qsTr("No tracks in playlist")
			hintText: qsTr("Pull down to add tracks")
		}

//		delegate: PlaylistItem
//		{
//			id: itemp
//			onClicked: playerControlPanel.visibleSize == 0 ? playerControlPanel.show() : playerControlPanel.hide()
//			onPushAndHold: { playController.playTrack(index); }
//		}

//		section
//		{
//			property: "section"
//			delegate: PlaylistSectionHeader {}
//		}

		VerticalScrollDecorator {}

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("About")
				onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
			}

			MenuItem
			{
				text: qsTr("Settings")
				onClicked: pageStack.push(Qt.resolvedUrl("SettingsPage.qml"))
			}

			MenuItem
			{
				text: qsTr("Equalizer")
				onClicked: pageStack.push(Qt.resolvedUrl("EqualizerPage.qml"))
			}

			MenuItem
			{
				text: qsTr("Add Folder")

				onClicked:
				{
//					var dialog = pageStack.push(Qt.resolvedUrl("AddFilesDialog.qml"),
//							{
//								directoryPath: fsHelper.exists(settings.lastAddFilesDirectoryPath)
//											   ? settings.lastAddFilesDirectoryPath : settings.defaultAddFilesDirectoryPath
//							});

//					dialog.accepted.connect(function()
//					{
//						settings.lastAddFilesDirectoryPath = dialog.directoryPath;
//						playlist.addTracksFromPath(dialog.directoryPath);
//					});
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
//					onClicked: remorse.execute(qsTr("Clearing"), function() { playlist.clearPlaylist() })
				}

//				PlayOrderControl
//				{
////					onOrderChange: playlist.playOrder = order
////					Component.onCompleted: setOrder(playlist.playOrder)
//				}
			}
		}
	}

//	PlayerControlPanel
//	{
//		id: playerControlPanel

//		Component.onCompleted:
//		{
//			player.currentDurationUpdated.connect(playerControlPanel.setTrackDuration);
//			player.currentPositionUpdated.connect(playerControlPanel.setTrackPosition);
//			player.stateChanged.connect(playerControlPanel.setPlayerState);
//		}

//		Component.onDestruction:
//		{
//			player.stateChanged.disconnect(playerControlPanel.setPlayerState);
//			player.currentDurationUpdated.disconnect(playerControlPanel.setTrackDuration);
//			player.currentPositionUpdated.disconnect(playerControlPanel.setTrackPosition);
//		}

//		onPrevious: playController.previous();

//		onPlayPause:
//		{
//			if(state == AudioPlayerState.Playing)
//				player.pause();
//			else
//			{
//				if(state == AudioPlayerState.Ready && !playlist.hasTrackToPlay())
//					playlist.calculateAndSetTrackToPlay();

//				if(player.hasTrackToPlay())
//					playController.play();
//			}
//		}

//		onStop: player.stop()
//		onSeek: player.seek(milliseconds)
//		onNext: playController.next()
//	}
}

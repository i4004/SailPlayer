import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.FsHelper 1.0
import "../controls"
import "../controls/playlist"

Page
{
	id: page

	allowedOrientations: Orientation.All

	FsHelper{ id: fsHelper }

	SilicaListView
	{
		id: listView

		anchors.fill: parent
		anchors.bottomMargin: playerControlPanel.visible ? playerControlPanel.visibleSize : 0
		clip: true

		header: PageHeader { title: "Default Playlist" }

		model: playlist

		ViewPlaceholder
		{
			enabled: listView.count == 0
			text: qsTr("No tracks in playlist")
			hintText: qsTr("Pull down to add tracks")
		}

		delegate: PlaylistItem
		{
			onClicked: playerControlPanel.visibleSize == 0 ? playerControlPanel.show() : playerControlPanel.hide()
			onPushAndHold: { playController.playTrack(index); }
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
					var dialog = pageStack.push(Qt.resolvedUrl("AddFilesDialog.qml"),
							{
								directoryPath: fsHelper.exists(settings.lastAddFilesDirectoryPath)
											   ? settings.lastAddFilesDirectoryPath : settings.defaultAddFilesDirectoryPath
							});

					dialog.accepted.connect(function()
					{
						settings.lastAddFilesDirectoryPath = dialog.directoryPath;
						playlistController.addTracksFromPath(dialog.directoryPath);
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
					onClicked: remorse.execute(qsTr("Clearing"), function() { playlistController.clear() })
				}

				PlayOrderControl
				{
					onOrderChange: playlist.playOrder = order
					Component.onCompleted: setOrder(playlist.playOrder)
				}
			}
		}
	}

	PlayerControlPanel
	{
		id: playerControlPanel

		Component.onCompleted:
		{
			player.CurrentDurationUpdated.connect(playerControlPanel.setTrackDuration);
			player.CurrentPositionUpdated.connect(playerControlPanel.setTrackPosition);
			player.StateChanged.connect(playerControlPanel.setPlayerState);
		}

		onPrevious: playController.previous()
		onPlayPause: playController.playPause()
		onStop: playController.stop()
		onSeek: playController.seek(milliseconds)
		onNext: playController.next()
	}
}

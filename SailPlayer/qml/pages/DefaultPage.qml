import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.PlaylistModel 1.0
import "../controls"
import "../Util.js" as Util

Page
{
	id: page

	AudioPlayer { id: player }

	allowedOrientations: Orientation.All

	Component.onCompleted:
	{
		player.setTrackForPlaying(playlist.getTrackPathForPlaying())
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
				playlist.setTrackForPlaying(index);
				player.setTrackForPlaying(playlist.getTrackPathForPlaying());
				playlist.setPlaying(true);
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
						listView.model.addTracks(dialog.directoryPath);
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
			MenuItem
			{
				text: qsTr("Order: default")
			}

			MenuItem
			{
				text: qsTr("Clear Playlist")
				onClicked: remorse.execute(qsTr("Clearing"), function() { listView.model.clearPlaylist() })
			}
		}
	}

	PlayerControlPanel
	{
		id: playerControlPanel

		onPlayPause:
		{
			if(isPlaying)
				player.pause();
			else
				player.play();

			isPlaying = !isPlaying;
			playlist.setPlaying(isPlaying);
		}

		onStop:
		{
			player.stop();
			isPlaying = false;
		}
	}
}

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
//		player.play();
	}

	// Playlist
	SilicaListView
	{
		id: listView

		anchors.fill: parent
		header: PageHeader { title: "Default Playlist" }

		clip: true

		model: PlaylistModel {}

		delegate: PlaylistItem
		{
			onClicked:
			{
				playerControlPanel.show()
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

		PlayerControlPanel
		{
			id: playerControlPanel

//			PushUpMenu
//			{
//				MenuItem
//				{
//					text: qsTr("Order: default")
//				}

//				MenuItem
//				{
//					text: qsTr("Clear Playlist")
//					onClicked: remorse.execute(qsTr("Clearing"), function() { listView.model.clearPlaylist() })
//				}
//			}
		}
	}
}

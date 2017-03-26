import QtQuick 2.0
import Sailfish.Silica 1.0

import "../controls"

Page
{
	id: page

	allowedOrientations: Orientation.All

	SilicaListView
	{
		id: list

		anchors.fill: parent

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("Create")
				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../dialogs/TextItemDialog.qml"),
					{
						placeholder: qsTr("Playlist Name"),
						title: qsTr("Create New Playlist")
					});

					dialog.accepted.connect(function() { spController.createPlaylist(dialog.value); })
				}
			}
		}

		header: PageHeader
		{
			title: qsTr("Playlists")
		}

		model: playlistsModel

		delegate: PlaylistsPlaylistItem
		{
			onClicked: pageStack.pop()
		}

		ViewPlaceholder
		{
			enabled: list.count == 0
			text: qsTr("No playlists")
			hintText: qsTr("Pull down to create new playlist")
		}
	}
}

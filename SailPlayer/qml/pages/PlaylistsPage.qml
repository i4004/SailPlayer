import QtQuick 2.0
import Sailfish.Silica 1.0

import "../components"

Page
{
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

					dialog.accepted.connect(function() { list.controller.createPlaylist(dialog.value); })
				}
			}
		}

		header: PageHeader
		{
			title: qsTr("Playlists")
		}

		property QtObject controller: playlistsControllerFactory.create()
		model: controller.getModel()

		delegate: PlaylistsPlaylistItem
		{
			controller: list.controller
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

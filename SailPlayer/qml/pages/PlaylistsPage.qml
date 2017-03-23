import QtQuick 2.0
import Sailfish.Silica 1.0

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

					dialog.accepted.connect(function() { playlistsController.createPlaylist(dialog.value); })
				}
			}
		}

		header: PageHeader
		{
			title: qsTr("Playlists")
		}

		model: playlistsModel

		delegate: ListItem
		{
			id: item
			menu: itemContextMenu

			Label
			{
				anchors
				{
					left: parent.left
					right: parent.right
					leftMargin: Theme.horizontalPageMargin
					rightMargin: Theme.horizontalPageMargin
					verticalCenter: parent.verticalCenter
				}

				wrapMode: Text.WordWrap

				text: name
			}

			ContextMenu
			{
				id: itemContextMenu

				MenuItem
				{
					text: qsTr("Rename")
					onClicked:
					{
						var dialog = pageStack.push(Qt.resolvedUrl("../dialogs/TextItemDialog.qml"),
						{
							placeholder: qsTr("Playlist Name"),
							title: qsTr("Playlist Name"),
							value:  name
						});

						dialog.accepted.connect(function() { playlistsController.renamePlaylist(id, dialog.value); })
					}
				}

				MenuItem
				{
					text: qsTr("Delete")
					onClicked: remorseItem.execute(item, qsTr("Deleting"), function() { playlistsController.deletePlaylist(id); })
				}
			}

			RemorseItem
			{
				id: remorseItem
			}
		}

		ViewPlaceholder
		{
			enabled: list.count == 0
			text: qsTr("No playlists")
			hintText: qsTr("Pull down to create new playlist")
		}
	}
}

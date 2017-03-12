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
				text: qsTr("Add New")
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
				}

				MenuItem
				{
					text: qsTr("Delete")
					onClicked: remorseItem.execute(item, qsTr("Deleting"), function() { playlistsController.deletePlaylist(index); })
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
			hintText: qsTr("Pull down to create new playlists")
		}
	}
}

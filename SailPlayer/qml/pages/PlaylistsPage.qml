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

		header: PageHeader
		{
			title: qsTr("Playlists")
		}

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("Add New")
			}
		}

		ViewPlaceholder
		{
			enabled: list.count == 0
			text: qsTr("No playlists")
			hintText: qsTr("Pull down to create new playlists")
		}

		model: ListModel
		{
			ListElement
			{
				name: "Dream Theater"
			}

			ListElement
			{
				name: "Communic"
			}
		}

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

			Component
			{
				id: itemContextMenu

				ContextMenu
				{
					MenuItem
					{
						text: qsTr("Rename")
					}

					MenuItem
					{
						text: qsTr("Delete")
						onClicked: remorseItem.execute(item, qsTr("Deleting"), function() { })
					}
				}
			}

			RemorseItem
			{
				id: remorseItem
			}
		}
	}
}

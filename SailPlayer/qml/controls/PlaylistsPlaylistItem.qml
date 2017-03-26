import QtQuick 2.0
import Sailfish.Silica 1.0

ListItem
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
		color: item.highlighted || spState.activePlaylistID == id ? Theme.highlightColor : Theme.primaryColor

		text: name
	}

	onClicked: spController.activatePlaylist(id)

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

				dialog.accepted.connect(function() { spController.renamePlaylist(id, dialog.value); })
			}
		}

		MenuItem
		{
			text: qsTr("Delete")
			onClicked: remorseItem.execute(item, qsTr("Deleting"), function() { spController.deletePlaylist(id); })
		}
	}

	RemorseItem
	{
		id: remorseItem
	}
}

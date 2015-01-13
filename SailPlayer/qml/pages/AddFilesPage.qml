import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.FilesListModel 1.0

Dialog
{
	id: dialog

	property string dir: "/"

	FilesListModel
	{
		id: filesListModel
		dir: dialog.dir
	}

	SilicaListView
	{
		id: filesList
		anchors.fill: parent

		model: filesListModel

		VerticalScrollDecorator { flickable: filesList }

		DialogHeader
		{
			id: dialogHeader
			title: qsTr("Add Files To Playlist")
			acceptText: qsTr("Add")
		}

		delegate: ListItem
		{
			id: fileItem
			contentHeight: listLabel.height

			Label
			{
				id: listLabel
				anchors.left: parent.left
				anchors.top: parent.top
				//anchors.topMargin: dialogHeader.height
				anchors.leftMargin: Theme.paddingLarge
				anchors.rightMargin: Theme.paddingLarge
				text: fileName
			}
		}
	}
}

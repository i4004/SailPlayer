import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.FilesListModel 1.0

Page
{
	id: page

	FilesListModel
	{
		id: filesListModel
	}

	SilicaListView
	{
		id: filesList
		anchors.fill: parent

		model: filesListModel

		DialogHeader
		{
			id: dialogHeader
			title: qsTr("Add Files To Playlist")
			acceptText: qsTr("Add")
		}
	}
}

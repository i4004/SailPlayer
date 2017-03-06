import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	id: page

	allowedOrientations: Orientation.All

	SilicaListView
	{
		id: listView

		anchors.fill: parent

		header: PageHeader
		{
			title: qsTr("Playlist")
		}

		ViewPlaceholder
		{
			enabled: listView.count == 0
			text: qsTr("No tracks in playlist")
			hintText: qsTr("Pull down to add tracks")
		}
	}
}

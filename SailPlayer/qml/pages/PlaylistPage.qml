import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	id: page

	allowedOrientations: Orientation.All

//	onStatusChanged:
//	{
//		if((status !== PageStatus.Active) || canNavigateForward)
//			return;

//		pageStack.pushAttached(Qt.resolvedUrl("TrackInfoPage.qml"));
//	}

	SilicaListView
	{
		id: listView

		anchors.fill: parent

		header: PageHeader
		{
			title: qsTr("Playlist")
		}

		PullDownMenu
		{		
			MenuItem
			{
				text: qsTr("Playlists")
				onClicked: pageStack.push(Qt.resolvedUrl("PlaylistsPage.qml"))
			}
		}

		ViewPlaceholder
		{
			enabled: listView.count == 0
			text: qsTr("No tracks in playlist")
			hintText: qsTr("Pull down to add tracks")
		}
	}
}

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
			title: spState.activePlaylistName
		}

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("Playlists")
				onClicked: pageStack.push(Qt.resolvedUrl("PlaylistsPage.qml"))
			}

			MenuItem
			{
				text: qsTr("Add Folder")
				enabled: spState.isPlaylistActive

				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../dialogs/DirectorySelectionDialog.qml"),
							{
								directoryPath: settings.lastDirectorySelectionPath
							});

					dialog.accepted.connect(function()
					{
						settings.lastDirectorySelectionPath = dialog.directoryPath;
//						playlistController.addTracksFromPath(dialog.directoryPath);
					});
				}
			}
		}

		property QtObject controller: playlistControllerFactory.create()
		model: controller.getModel()

		ViewPlaceholder
		{
			enabled: listView.count == 0 && spState.isPlaylistActive
			text: qsTr("No tracks in playlist")
			hintText: qsTr("Pull down to add tracks")
		}

		ViewPlaceholder
		{
			enabled: !spState.isPlaylistActive
			text: qsTr("No playlist selected")
			hintText: qsTr("Pull down to go to playlists management")
		}
	}
}

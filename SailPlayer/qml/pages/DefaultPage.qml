import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.PlaylistModel 1.0

Page
{
    id: page

	AudioPlayer { id: player }

	allowedOrientations: Orientation.All

	Component.onCompleted:
	{
//		player.play();
	}

	SilicaListView
	{
		id: listView
		model: PlaylistModel {}

		anchors.fill: parent
		header: PageHeader { title: "Default Playlist" }

		delegate: Column
		{
			width: parent.width

			Label
			{
				width: parent.width
				x: Theme.paddingMedium
//				text: artist
				wrapMode: Text.WordWrap
				color: Theme.highlightColor
				font.pixelSize: Theme.fontSizeLarge
			}

			Label
			{
				width: parent.width
				x: Theme.paddingMedium
//				text: "[" + year + "] " + album
				wrapMode: Text.WordWrap
				color: Theme.secondaryColor
				font.pixelSize: Theme.fontSizeTiny
			}

			Repeater
			{
				id: songsList
				width: parent.width

				BackgroundItem
				{
					id: item
					height: label.height + Theme.paddingSmall

					Label
					{
						id: label
						width: parent.width
						x: Theme.paddingLarge + 10
						anchors.verticalCenter: parent.verticalCenter
//						text: trackNumber + " " + songName
						color: item.highlighted ? Theme.highlightColor : Theme.primaryColor
					}

					Label
					{
						anchors.verticalCenter: parent.verticalCenter
						anchors.right: parent.right
						anchors.rightMargin: Theme.paddingMedium
//						text: duration
						color: item.highlighted ? Theme.highlightColor : Theme.secondaryColor
					}
				}
			}
		}

		VerticalScrollDecorator {}

		PullDownMenu
		{
			MenuItem
			{
				text: qsTr("About")
				onClicked: pageStack.push(Qt.resolvedUrl("../Pages/About.qml"))
			}

			MenuItem
			{
				text: qsTr("Settings")
				onClicked: pageStack.push(Qt.resolvedUrl("../Pages/Settings.qml"))
			}

			MenuItem
			{
				text: qsTr("Add")

				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../Pages/AddFilesDialog.qml"));

					dialog.accepted.connect(function()
					{
						listView.model.addTracks(dialog.directoryPath);
					});
				}
			}
		}
	}
}

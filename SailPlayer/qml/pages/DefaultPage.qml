import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.AudioPlayer 1.0
import harbour.sail.player.PlaylistModel 1.0
import "../Util.js" as Util

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
		model: PlaylistModel { id: playlistModel }

		anchors.fill: parent
		header: PageHeader { title: "Default Playlist" }

		delegate: BackgroundItem
		{
			id: item
			height: labelTrackName.height + Theme.paddingSmall

			Label
			{
				id: labelTrackNumber
				anchors.left: parent.left
				anchors.leftMargin: Theme.paddingLarge + 10
				anchors.verticalCenter: parent.verticalCenter
				text: Util.zeroPad(trackNumber, 2)
				color: item.highlighted ? Theme.highlightColor : Theme.primaryColor
			}

			Label
			{
				id: labelTrackName
				anchors.left: labelTrackNumber.right
				anchors.leftMargin: Theme.paddingMedium
				anchors.right: labelTrackDuration.left
				anchors.verticalCenter: parent.verticalCenter
				text: trackName
				color: item.highlighted ? Theme.highlightColor : Theme.primaryColor
				wrapMode: Text.WordWrap
			}

			Label
			{
				id: labelTrackDuration
				anchors.verticalCenter: parent.verticalCenter
				anchors.right: parent.right
				anchors.rightMargin: Theme.paddingMedium
				text: Util.formatTrackDuration(trackDuration)
				color: item.highlighted ? Theme.highlightColor : Theme.secondaryColor
			}
		}

		section
		{
			property: "section"
			delegate: Component
			{
				Column
				{
					width: parent.width

					property var sectionSplit: section.split("\u0001")

					Label
					{
						width: parent.width
						x: Theme.paddingMedium
						text: sectionSplit[0]
						wrapMode: Text.WordWrap
						color: Theme.highlightColor
						font.pixelSize: Theme.fontSizeLarge
					}

					Label
					{
						width: parent.width
						x: Theme.paddingMedium
						text: "[" + sectionSplit[1] + "] " + sectionSplit[2]
						wrapMode: Text.WordWrap
						color: Theme.secondaryColor
						font.pixelSize: Theme.fontSizeTiny
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
				onClicked: pageStack.push(Qt.resolvedUrl("../pages/About.qml"))
			}

			MenuItem
			{
				text: qsTr("Settings")
				onClicked: pageStack.push(Qt.resolvedUrl("../pages/Settings.qml"))
			}

			MenuItem
			{
				text: qsTr("Add")

				onClicked:
				{
					var dialog = pageStack.push(Qt.resolvedUrl("../pages/AddFilesDialog.qml"));

					dialog.accepted.connect(function()
					{
						listView.model.addTracks(dialog.directoryPath);
					});
				}
			}
		}
	}
}

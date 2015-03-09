import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.LastFmError 1.0
import "../../controls"

Page
{
	id: page

	allowedOrientations: Orientation.All

	SilicaFlickable
	{
		anchors.fill: parent
		contentHeight: column.height

		Column
		{
			id: column

			anchors.left: parent.left
			anchors.right: parent.right

			PageHeader { title: qsTr("Settings") }

			SectionHeader { text: qsTr('General') }

			TextSwitch
			{
				checked: settings.restoreLastPlayingPosition

				text: qsTr("Restore last playing position on startup")

				onClicked: settings.restoreLastPlayingPosition = !settings.restoreLastPlayingPosition;
			}

			SectionHeader { text: qsTr('Last.fm') }

			Row
			{
				anchors.horizontalCenter: parent.horizontalCenter

				Button
				{
				   text: qsTr("Last.fm settings")
				   onClicked: pageStack.push(Qt.resolvedUrl("LastFmSettings.qml"));
				}
			}
		}
	}
}

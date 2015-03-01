import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
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

			SectionHeader
			{
				text: qsTr('General')
			}

			TextSwitch
			{
				text: qsTr("Restore last playing position on startup")
			}

			SectionHeader
			{
				text: qsTr('Last.fm')
			}

			TextSwitch
			{
				text: qsTr("Scrobbling is enabled")
			}

			Label
			{
				anchors.left: parent.left
				anchors.leftMargin: Theme.paddingLarge
				anchors.right: parent.right
				anchors.rightMargin: Theme.paddingLarge

				font.pixelSize: Theme.fontSizeTiny
				wrapMode: Text.WordWrap
				color: Theme.secondaryColor
				text: qsTr("Enter your last.fm credentials if you want to scrobble your songs to Last.fm. Only Last.fm session ID will be saved on the device.")
			}

			TextField
			{
				id: lastFmUserName

				placeholderText: qsTr('User name')
				width: parent.width
			}

			TextField
			{
				placeholderText: qsTr('Password')
				width: parent.width
			}

			Row
			{
				anchors.horizontalCenter: parent.horizontalCenter

				Button
				{
				   text: qsTr('Authenticate on Last.fm')
				}
			}
		}
	}
}

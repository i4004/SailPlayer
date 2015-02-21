import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	allowedOrientations: Orientation.All

	property string message: '';

	SilicaFlickable
	{
		anchors.fill: parent
		contentHeight: column.height

		Column
		{
			id: column
			anchors.left: parent.left
			anchors.right: parent.right

			PageHeader { title: qsTr("Playback error") }

			Label
			{
				anchors.left: parent.left
				anchors.right: parent.right
				anchors.leftMargin: Theme.paddingLarge
				anchors.rightMargin: Theme.paddingLarge
				wrapMode: Text.Wrap
				color: Theme.primaryColor

				text: message
			}
		}
	}
}

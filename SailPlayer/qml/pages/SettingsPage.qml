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

			Row
			{
				anchors.horizontalCenter: parent.horizontalCenter

				Button
				{
				   text: qsTr("Equalizer")
				   onClicked: pageStack.push(Qt.resolvedUrl("EqualizerSettingsPage.qml"));
				}
			}
		}
	}
}

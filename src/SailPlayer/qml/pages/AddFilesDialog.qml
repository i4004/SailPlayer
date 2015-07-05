import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.FsRecordsListModel 1.0

Dialog
{
	id: dialog

	property string directoryPath: '';

	allowedOrientations: Orientation.All

	SilicaListView
	{
		id: itemsList

		anchors.fill: parent

		model: FsRecordsListModel
		{
			id: fsRecordsListModel
			directoryPath: dialog.directoryPath;
		}

		header: DialogHeader
		{
			id: dialogHeader

			title: fsRecordsListModel.directoryPath
			acceptText: qsTr("Add")
		}

		VerticalScrollDecorator { flickable: itemsList }

		delegate: ListItem
		{
			id: listItem

			contentHeight: listItemLabel.height + Theme.paddingMedium

			Image
			{
				id: listItemIcon

				anchors.left: parent.left
				anchors.leftMargin: Theme.paddingLarge

				anchors.verticalCenter: parent.verticalCenter

				source: "../images/icons/small-" + iconName + ".png"
			}

			Label
			{
				id: listItemLabel

				anchors.left: listItemIcon.right
				anchors.right: parent.right

				anchors.leftMargin: Theme.paddingMedium
				anchors.rightMargin: Theme.paddingLarge

				anchors.verticalCenter: parent.verticalCenter

				text: name
				wrapMode: Text.WordWrap
			}

			onClicked:
			{
				if(isDirectory)
					fsRecordsListModel.directoryPath = model.filePath
			}
		}
	}

	onAccepted: directoryPath = fsRecordsListModel.directoryPath
}

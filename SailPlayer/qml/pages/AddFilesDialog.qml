import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.FilesListModel 1.0

Dialog
{
	id: dialog

	property string dir: "/"

	FilesListModel
	{
		id: filesListModel
		dir: dialog.dir
	}

	SilicaListView
	{
		id: filesList

		anchors.fill: parent

		model: filesListModel

		VerticalScrollDecorator { flickable: filesList }

		header: DialogHeader
		{
			id: dialogHeader

			title: dialog.dir
			acceptText: qsTr("Add")
		}

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

				source: "../images/icons/small-" + fileIconName + ".png"
			}

			Label
			{
				id: listItemLabel

				anchors.left: listItemIcon.right
				anchors.right: parent.right

				anchors.leftMargin: Theme.paddingMedium
				anchors.rightMargin: Theme.paddingLarge

				anchors.verticalCenter: parent.verticalCenter

				text: fileName
			}
		}
	}
}

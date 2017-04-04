import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog
{
	allowedOrientations: Orientation.All

	property string directoryPath: "";

	SilicaListView
	{
		id: list

		anchors.fill: parent

		header: DialogHeader
		{
			title: list.controller.directoryPath
			acceptText: qsTr("Select")
		}

		property QtObject controller: directorySelectionControllerFactory.create()
		model: controller.getModel()

		Component.onCompleted:
		{
			controller.directoryPath = directoryPath;
		}

		delegate: ListItem
		{
			contentHeight: listItemLabel.height + Theme.paddingMedium

			Image
			{
				id: listItemIcon

				anchors
				{
					left: parent.left
					leftMargin: Theme.paddingLarge
					verticalCenter: parent.verticalCenter
				}

				source: "../images/icons/small-" + iconName + ".png"
			}

			Label
			{
				id: listItemLabel

				anchors
				{
					left: listItemIcon.right
					right: parent.right

					leftMargin: Theme.paddingMedium
					rightMargin: Theme.paddingLarge

					verticalCenter: parent.verticalCenter
				}

				text: name
				wrapMode: Text.WordWrap
				truncationMode: TruncationMode.Fade
			}

			onClicked:
			{
				if(isDirectory)
					list.controller.directoryPath = model.filePath
			}
		}

		VerticalScrollDecorator { flickable: list }
	}

	onAccepted: directoryPath = list.controller.directoryPath
}

import QtQuick 2.0
import Sailfish.Silica 1.0

Page
{
	allowedOrientations: Orientation.All

	property string message: ''
	property string pageTitle: ''

	SilicaFlickable
	{
		anchors.fill: parent
		contentHeight: column.height

		Column
		{
			id: column
			anchors.left: parent.left
			anchors.right: parent.right

			PageHeader { title: pageTitle }

			TextArea
			{
				anchors.left: parent.left
				anchors.right: parent.right

				color: Theme.primaryColor
				wrapMode: Text.Wrap
				readOnly: true
				focusOnClick: true

				text: message
			}
		}
	}
}

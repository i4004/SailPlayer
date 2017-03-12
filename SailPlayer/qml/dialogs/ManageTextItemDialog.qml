import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog
{
	property string placeholder
	property string value
	property string title: ''

	allowedOrientations: Orientation.All

	canAccept: input.text.length > 0

	Column
	{
		anchors.left: parent.left
		anchors.right: parent.right

		DialogHeader { title: title }

		TextField
		{
			id: input

			width: parent.width

			placeholderText: placeholder
			text: value
		}
	}

	onAccepted: value = input.text
}

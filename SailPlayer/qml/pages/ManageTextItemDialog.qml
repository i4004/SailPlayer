import QtQuick 2.0
import Sailfish.Silica 1.0

Dialog
{
	property string inputName
	property string value
	property string dialogTitle: ''

	canAccept: valueInput.text.length > 0

	Column
	{
		anchors.left: parent.left
		anchors.right: parent.right

		DialogHeader { title: dialogTitle }

		TextField
		{
			id: valueInput

			width: parent.width
			placeholderText: inputName
			text: value
		}
	}

	onDone: value = valueInput.text
}

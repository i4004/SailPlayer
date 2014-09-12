import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle
{
	width: 100
	height: 62

	Label
	{
		x: Theme.paddingLarge
		text: qsTr("test")
		anchors.verticalCenter: parent.verticalCenter
		color: delegate.highlighted ? Theme.highlightColor : Theme.primaryColor
	}
}

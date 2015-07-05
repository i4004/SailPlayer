import QtQuick 2.0
import Sailfish.Silica 1.0

Component
{
	Column
	{
		width: parent.width

		property var sectionSplit: section.split("\u0001")

		Label
		{
			width: parent.width
			x: Theme.paddingMedium
			text: sectionSplit[0] !== "" ? sectionSplit[0] : "?"
			wrapMode: Text.NoWrap
			truncationMode: TruncationMode.Fade
			color: Theme.highlightColor
			font.pixelSize: Theme.fontSizeLarge
		}

		Label
		{
			width: parent.width
			x: Theme.paddingMedium
			text: (sectionSplit[1] !== 0 ? "[" + sectionSplit[1] + "] " : "?") + sectionSplit[2]
			wrapMode: Text.NoWrap
			truncationMode: TruncationMode.Fade
			color: Theme.secondaryColor
			font.pixelSize: Theme.fontSizeTiny
		}
	}
}

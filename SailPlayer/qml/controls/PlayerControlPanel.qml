import QtQuick 2.0
import Sailfish.Silica 1.0

DockedPanel
{
	id: dockPanel
	width: parent.width

	height: Theme.itemSizeExtraLarge + Theme.paddingLarge
	dock: Dock.Bottom

	Row
	{
		anchors.centerIn: parent

		Switch { icon.source: "image://theme/icon-l-shuffle" }
		Switch { icon.source: "image://theme/icon-l-repeat" }
		Switch { icon.source: "image://theme/icon-l-share" }
	}
}

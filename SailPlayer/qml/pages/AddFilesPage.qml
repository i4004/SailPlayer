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

//	Column
//	{
//		anchors.fill: parent

		SilicaListView
		{
			id: filesList
			anchors.fill: parent

			model: filesListModel

			VerticalScrollDecorator { flickable: filesList }

//			DialogHeader
//			{
//				id: dialogHeader
//				title: qsTr("Add Files To Playlist")
//				acceptText: qsTr("Add")
//			}

//			delegate: ListItem
//			{
//				id: fileItem
	//			menu: contextMenu
//				width: ListView.view.width
	//			contentHeight: listLabel.height//+listSize.height + 13

//				Label
//				{
//					id: listLabel
//					anchors.left: parent.left//listIcon.right
//					anchors.leftMargin: Theme.paddingLarge
//					anchors.right: parent.right
//					anchors.rightMargin: Theme.paddingLarge
	//				anchors.top: parent.top
	//				anchors.topMargin: dialogHeader.height + Theme.paddingLarge
//					text: fileName
	//				height: contentHeight
	//				elide: Text.ElideRight
	//				color: /*fileItem.highlighted || isSelected ? Theme.highlightColor :*/ Theme.primaryColor
//				}

	//			Label
	//			{
	//                id: listSize
	//                anchors.left: listIcon.right
	//                anchors.leftMargin: 10
	//                anchors.top: listLabel.bottom
	//                text: !(isLink && isDir) ? size : Functions.unicodeArrow()+" "+symLinkTarget
	//                color: fileItem.highlighted || isSelected ? Theme.secondaryHighlightColor : Theme.secondaryColor
	//                font.pixelSize: Theme.fontSizeExtraSmall
	//            }
//			}
		}
//	}
}

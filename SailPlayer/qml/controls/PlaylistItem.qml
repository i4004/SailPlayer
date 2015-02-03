import QtQuick 2.0
import Sailfish.Silica 1.0

import "../Util.js" as Util

BackgroundItem
{
	id: item
	height: labelTrackName.height + Theme.paddingSmall

	Label
	{
		id: labelTrackNumber
		anchors.left: parent.left
		anchors.leftMargin: Theme.paddingLarge + 10
		anchors.verticalCenter: parent.verticalCenter
		text: trackNumber != 0 ? Util.zeroPad(trackNumber, 2) : ""
		color: item.highlighted ? Theme.highlightColor : Theme.primaryColor
	}

	Label
	{
		id: labelTrackName
		anchors.left: labelTrackNumber.right
		anchors.leftMargin: Theme.paddingMedium
		anchors.right: labelTrackDuration.left
		anchors.verticalCenter: parent.verticalCenter
		text: trackName != "" ? trackName : trackFileName
		color: item.highlighted ? Theme.highlightColor : Theme.primaryColor
		wrapMode: Text.WordWrap
	}

	Label
	{
		id: labelTrackDuration
		anchors.verticalCenter: parent.verticalCenter
		anchors.right: parent.right
		anchors.rightMargin: Theme.paddingMedium
		text: Util.formatTrackDuration(trackDuration)
		color: item.highlighted ? Theme.highlightColor : Theme.secondaryColor
	}
}

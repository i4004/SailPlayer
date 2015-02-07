import QtQuick 2.0
import Sailfish.Silica 1.0

import "../../Util.js" as Util

BackgroundItem
{
	id: item
	height: labelTrackName.height + Theme.paddingSmall

	signal pushAndHold

	Image
	{
		id: playArrow
		anchors.left: parent.left
		anchors.leftMargin: Theme.paddingSmall
		anchors.verticalCenter: parent.verticalCenter
		source: "../../images/icons/icon-m-play-arrow.png"
		visible: isPlaying
	}

	Label
	{		
		id: labelTrackNumber
		anchors.left: playArrow.right
		anchors.leftMargin: Theme.paddingSmall
		anchors.verticalCenter: parent.verticalCenter
		text: trackNumber != 0 ? Util.zeroPad(trackNumber, 2) : ""
		color: item.highlighted || isTrackToPlay ? Theme.highlightColor : Theme.primaryColor
	}

	Label
	{
		id: labelTrackName
		anchors.left: labelTrackNumber.right
		anchors.leftMargin: Theme.paddingMedium
		anchors.right: labelTrackDuration.left
		anchors.verticalCenter: parent.verticalCenter
		text: trackName != "" ? trackName : trackFileName
		color: item.highlighted || isTrackToPlay ? Theme.highlightColor : Theme.primaryColor
		wrapMode: Text.WordWrap
	}

	Label
	{
		id: labelTrackDuration
		anchors.verticalCenter: parent.verticalCenter
		anchors.right: parent.right
		anchors.rightMargin: Theme.paddingMedium
		text: Util.formatTrackDuration(trackDuration)
		color: item.highlighted || isTrackToPlay ? Theme.highlightColor : Theme.secondaryColor
	}

	onPressed:
	{
		pushAndHoldTimer.restart();
	}

	Timer
	{
		id: pushAndHoldTimer

		onTriggered:
		{
			if(item.highlighted)
				item.pushAndHold();
		}
	}
}

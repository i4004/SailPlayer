import QtQuick 2.0
import harbour.sail.player.PlayOrder 1.0
import "radio"

Row
{
	signal orderChange(int order)

	function setOrder(order)
	{
		if(order === PlayOrder.Default)
			orderDefault.check();
		else if(order === PlayOrder.RepeatPlaylist)
			orderRepeatPlaylist.check();
		else if(order === PlayOrder.RepeatTrack)
			orderRepeatTrack.check();
		else if(order === PlayOrder.Random)
			orderRandom.check();
	}

	anchors.horizontalCenter: parent.horizontalCenter
	spacing: 38

	RadioGroup { id: radioGroup }

	RadioSwitch
	{
		id: orderDefault
		icon.source: "../images/icons/icon-m-no-repeat.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.Default)
	}

	RadioSwitch
	{
		id: orderRepeatPlaylist
		icon.source: "image://theme/icon-m-repeat"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.RepeatPlaylist)
	}

	RadioSwitch
	{
		id: orderRepeatTrack
		icon.source: "../images/icons/icon-m-repeat-track.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.RepeatTrack)
	}

	RadioSwitch
	{
		id: orderRandom
		icon.source: "../images/icons/icon-m-random.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.Random)
	}
}

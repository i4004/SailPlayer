import QtQuick 2.0
import harbour.sail.player.PlayOrder 1.0

Row
{
	anchors.horizontalCenter: parent.horizontalCenter
	spacing: 38

	signal orderChange(int order)

	function setOrder(order)
	{
		if(order === PlayOrder.Default)
			orderDefault.check();
		else if(order === PlayOrder.RepeatPlaylist)
			orderRepeatPlaylist.check();
		else if(order === PlayOrder.RepeatTrack)
			orderRepeatTrack.check();
		else if(order === PlayOrder.RepeatPlaylist)
			orderRandom.check();
	}

	RadioGroup { id: radioGroup }

	RadioSwitch
	{
		id: orderDefault
		icon.source: "../images/icons/icon-m-stop.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.Default)
	}

	RadioSwitch
	{
		id: orderRepeatPlaylist
		icon.source: "../images/icons/icon-m-stop.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.RepeatPlaylist)
	}

	RadioSwitch
	{
		id: orderRepeatTrack
		icon.source: "../images/icons/icon-m-stop.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.RepeatTrack)
	}

	RadioSwitch
	{
		id: orderRandom
		icon.source: "../images/icons/icon-m-stop.png"
		radioGroup: radioGroup
		onClicked: orderChange(PlayOrder.Random)
	}
}

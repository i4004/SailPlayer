import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"
import "controls"

ApplicationWindow
{
	Component.onCompleted: player.PlaybackError.connect(messagePage.displayMessage);

	MessagePageDisplayer
	{
		id: messagePage
		title: qsTr("Playback error")
	}

	initialPage: Component { MainPage {} }
	cover: Qt.resolvedUrl("Cover.qml")
}

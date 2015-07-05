import QtQuick 2.0

QtObject
{
	property string title: qsTr("Information")
	property var playbackErrorPage

	function displayMessage(message)
	{
		if(playbackErrorPage !== null && pageStack.currentPage === playbackErrorPage)
			return;

		playbackErrorPage = pageStack.push(Qt.resolvedUrl("../pages/MessagePage.qml"), { message: message, pageTitle: title });
	}
}

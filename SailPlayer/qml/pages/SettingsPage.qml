import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.sail.player.SailPlayerSettings 1.0
import harbour.sail.player.LastFmError 1.0
import "../controls"

Page
{
	id: page

	allowedOrientations: Orientation.All

	SilicaFlickable
	{
		anchors.fill: parent
		contentHeight: column.height

		Column
		{
			id: column

			anchors.left: parent.left
			anchors.right: parent.right

			PageHeader { title: qsTr("Settings") }

			SectionHeader
			{
				text: qsTr('General')
			}

			TextSwitch
			{
				checked: settings.restoreLastPlayingPosition

				text: qsTr("Restore last playing position on startup")

				onClicked: settings.restoreLastPlayingPosition = !settings.restoreLastPlayingPosition;
			}

			SectionHeader
			{
				text: qsTr('Last.fm')
			}

			TextSwitch
			{
				enabled: settings.lastFmSessionKey !== ""
				checked: settings.scrobblingIsEnabled

				text: qsTr("Scrobbling is enabled")

				onClicked: settings.scrobblingIsEnabled = !settings.scrobblingIsEnabled;
			}

			Label
			{
				anchors.left: parent.left
				anchors.leftMargin: Theme.paddingLarge
				anchors.right: parent.right
				anchors.rightMargin: Theme.paddingLarge

				font.pixelSize: Theme.fontSizeTiny
				wrapMode: Text.WordWrap
				color: Theme.secondaryColor

				text: qsTr("Enter your last.fm credentials if you want to scrobble your songs to Last.fm. Only Last.fm session key will be saved on the device.")
			}

			TextField
			{
				id: lastFmUserName

				width: parent.width

				placeholderText: qsTr('User name or e-mail')

				EnterKey.onClicked: lastFmPassword.focus = true
			}

			TextField
			{
				id: lastFmPassword

				width: parent.width
				echoMode: TextInput.Password

				placeholderText: qsTr('Password')

				EnterKey.onClicked: lastFmAuthenticateButton.focus = true
			}

			Button
			{
				id: lastFmAuthenticateButton

				anchors.horizontalCenter: parent.horizontalCenter

				enabled: settings.lastFmSessionKey !== "" || (settings.lastFmSessionKey === "" && lastFmUserName.text != "" && lastFmPassword.text != "")

				text: settings.lastFmSessionKey === "" ? qsTr('Authenticate on Last.fm') : qsTr('Clear Last.fm authentication')

				Component.onCompleted:
				{
					scrobbler.authenticated.connect(onAuthenticated);
					scrobbler.errorResponse.connect(onError);
				}

				onClicked:
				{
					if(settings.lastFmSessionKey !== "")
						remorse.execute(qsTr("Clearing"), function() { settings.lastFmSessionKey = ""; })
					else
					{
						lastFmAuthenticateButton.enabled = false;
						lastFmBusyIndicator.running = true;
						scrobbler.authenticate(lastFmUserName.text, lastFmPassword.text);
					}
				}

				function onAuthenticated(key)
				{
					lastFmBusyIndicator.running = false;
					lastFmAuthenticateButton.enabled = true;
					lastFmUserName.text = "";
					lastFmPassword.text = "";

					settings.lastFmSessionKey = key;
				}

				function onError(error, description)
				{
					lastFmBusyIndicator.running = false;
					lastFmAuthenticateButton.enabled = true;

					if(error === LastFmError.AuthenticationFailed)
						notifiicationPanel.showText(qsTr('Invalid user name or password.'));
					else if(error === LastFmError.NoInternetConnection)
						notifiicationPanel.showText(qsTr('No internet connection.'));
					else
						notifiicationPanel.showText(description);
				}
			}

			BusyIndicator
			{
				id: lastFmBusyIndicator

				anchors.horizontalCenter: parent.horizontalCenter
				size: BusyIndicatorSize.Small

				running: false
			}
		}

		NotificationPanel
		{
			id: notifiicationPanel

			page: page
		}

		RemorsePopup
		{
			id: remorse
		}
	}
}

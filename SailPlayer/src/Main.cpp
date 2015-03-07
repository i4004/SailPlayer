#include <QGuiApplication>
#include <QtQuick>
#include <sailfishapp.h>

#include "Net/LastFmRequestBuilder.hpp"
#include "SailPlayerController.hpp"

using namespace Net;

//#include "Audio/AudioPlayer.hpp"
//#include "Cue/CueSheetReader.hpp"
//#include "IO/FsHelper.hpp"
//#include "Models/FsRecordsListModel.hpp"
//#include "Models/PlaylistModel.hpp"
//#include "Net/LastFmScrobbler.hpp"
#include "SailPlayer.hpp"
#include "SailPlayerSettings.hpp"

//using namespace Audio;
//using namespace IO;
//using namespace Models;
//using namespace Playlist;

int main(int argc, char *argv[])
{
	qmlRegisterType<SailPlayer>("harbour.sail.player.PlayDirection", 1, 0, "PlayDirection");
	qmlRegisterType<SailPlayer>("harbour.sail.player.PlayOrder", 1, 0, "PlayOrder");
	qRegisterMetaType<SailPlayer::PlayDirection>("SailPlayer::PlayDirection");
	qRegisterMetaType<SailPlayer::PlayOrder>("SailPlayer::PlayOrder");

	qmlRegisterType<AudioPlayerBase>("harbour.sail.player.AudioPlayerState", 1, 0, "AudioPlayerState");
	qRegisterMetaType<AudioPlayerBase::AudioPlayerState>("AudioPlayerBase::AudioPlayerState");
	qRegisterMetaType<AudioPlayer::AudioPlayerState>("AudioPlayer::AudioPlayerState");

//	qmlRegisterType<AudioPlayer>("harbour.sail.player.AudioPlayer", 1, 0, "AudioPlayer");

//	qmlRegisterType<FsHelper>("harbour.sail.player.FsHelper", 1, 0, "FsHelper");
//	qmlRegisterType<FsRecordsListModel>("harbour.sail.player.FsRecordsListModel", 1, 0, "FsRecordsListModel");

//	qmlRegisterType<LastFmScrobbler>("harbour.sail.player.LastFmScrobbler", 1, 0, "LastFmScrobbler");
//	qmlRegisterType<LastFmScrobbler>("harbour.sail.player.LastFmError", 1, 0, "LastFmError");
//	qRegisterMetaType<LastFmScrobbler::LastFmError>("LastFmScrobbler::LastFmError");

	// Application description

	QCoreApplication::setOrganizationName("Alexander Krylkov");
	QCoreApplication::setApplicationName("Sail Player");

	LastFmRequestBuilder::SetApplicationName("Sail Player");
	LastFmRequestBuilder::SetApplicationVersion("0.2");
	LastFmRequestBuilder::SetContactUrl("https://github.com/i4004/SailPlayer");

	// Startup

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());
	SailPlayerController* controller = new SailPlayerController(&(*view));

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();
	int result = app->exec();

	delete controller;
	return result;
}

#include <QGuiApplication>
#include <QtQuick>

#include <sailfishapp.h>

#include "Audio/AudioPlayer.hpp"
#include "IO/FsHelper.hpp"
#include "Models/FsRecordsListModel.hpp"
#include "Models/PlaylistModel.hpp"
#include "SailPlayer.hpp"
#include "SailPlayerSettings.hpp"

#include "Cue/CueSheetReader.hpp"

using namespace Audio;
using namespace IO;
using namespace Models;\
using namespace Playlist;

int main(int argc, char *argv[])
{
	qmlRegisterType<AudioPlayer>("harbour.sail.player.AudioPlayer", 1, 0, "AudioPlayer");
	qmlRegisterType<AudioPlayerBase>("harbour.sail.player.AudioPlayerState", 1, 0, "AudioPlayerState");
	qRegisterMetaType<AudioPlayerBase::AudioPlayerState>("AudioPlayerBase::AudioPlayerState");
	qRegisterMetaType<AudioPlayer::AudioPlayerState>("AudioPlayer::AudioPlayerState");

	qmlRegisterType<FsHelper>("harbour.sail.player.FsHelper", 1, 0, "FsHelper");
	qmlRegisterType<FsRecordsListModel>("harbour.sail.player.FsRecordsListModel", 1, 0, "FsRecordsListModel");

	qmlRegisterType<PlaylistModel>("harbour.sail.player.PlaylistModel", 1, 0, "PlaylistModel");
	qmlRegisterType<SailPlayer>("harbour.sail.player.PlayDirection", 1, 0, "PlayDirection");
	qmlRegisterType<SailPlayer>("harbour.sail.player.PlayOrder", 1, 0, "PlayOrder");
	qRegisterMetaType<SailPlayer::PlayDirection>("SailPlayer::PlayDirection");
	qRegisterMetaType<SailPlayer::PlayOrder>("SailPlayer::PlayOrder");

	qmlRegisterType<SailPlayerSettings>("harbour.sail.player.SailPlayerSettings", 1, 0, "SailPlayerSettings");

	QCoreApplication::setOrganizationName("Alexander Krylkov");
	QCoreApplication::setApplicationName("Sail Player");

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

	return app->exec();
}

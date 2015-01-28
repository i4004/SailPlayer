#include <QGuiApplication>
#include <QtQuick>

#include <sailfishapp.h>

#include "Audio/AudioPlayer.h"
#include "IO/FsHelper.h"
#include "UI/FsRecordsListModel.h"
#include "SailPlayerSettings.h"
#include "Playlist/TracksListFactory.h"

using namespace Audio;
using namespace IO;
using namespace UI;\
using namespace Playlist;

int main(int argc, char *argv[])
{
	qmlRegisterType<AudioPlayer>("harbour.sail.player.AudioPlayer", 1, 0, "AudioPlayer");
	qmlRegisterType<FsHelper>("harbour.sail.player.FsHelper", 1, 0, "FsHelper");
	qmlRegisterType<FsRecordsListModel>("harbour.sail.player.FsRecordsListModel", 1, 0, "FsRecordsListModel");
	qmlRegisterType<SailPlayerSettings>("harbour.sail.player.SailPlayerSettings", 1, 0, "SailPlayerSettings");
	qmlRegisterType<TracksListFactory>("harbour.sail.player.TracksListFactory", 1, 0, "TracksListFactory");

	QCoreApplication::setOrganizationName("Alexander Krylkov");
	QCoreApplication::setApplicationName("Sail Player");

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

	return app->exec();
}

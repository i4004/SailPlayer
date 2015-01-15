#include <QApplication>
#include <QtQuick>

#include <sailfishapp.h>

#include "UI/FsRecordsListModel.h"
#include "UI/AudioPlayer.h"
#include "Entities/Artist.h"

#include <QtMultimedia/qmediaplayer.h>

using namespace UI;

int main(int argc, char *argv[])
{
	qmlRegisterType<FsRecordsListModel>("harbour.sail.player.FsRecordsListModel", 1, 0, "FsRecordsListModel");
	qmlRegisterType<AudioPlayer>("harbour.sail.player.AudioPlayer", 1, 0, "AudioPlayer");

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

	return app->exec();
}

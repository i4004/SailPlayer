#include <QGuiApplication>
#include <QtQuick>
#include <sailfishapp.h>

#include <stdio.h>
#include <execinfo.h>
#include <inttypes.h>
#include <signal.h>
#include <QDebug>

#include "IO/FsHelper.hpp"
#include "IO/FsRecordsListModel.hpp"
#include "Net/LastFmQueryBuilder.hpp"
#include "Net/LastFmRequestBuilder.hpp"
#include "Net/LastFmScrobbler.hpp"
#include "Playlist/PlaylistEnums.hpp"
#include "SailPlayerController.hpp"

using namespace IO;
using namespace Net;
using namespace Playlist;

void print_backtrace(void)
{
void* buf[64];
int size = backtrace(buf, 64);
printf("backtrace(%d):\n", size);
for (int i = 0; i < size; ++i)
printf(" %lx\n", (unsigned long)buf[i]);
}

void posix_death_signal(int signum)
{
	qDebug() << "error!";
	signal(signum, SIG_DFL);
	exit(3);
}

int main(int argc, char *argv[])
{
	signal(SIGSEGV, posix_death_signal);

	qmlRegisterType<PlaylistEnums>("harbour.sail.player.PlayOrder", 1, 0, "PlayOrder");
	qRegisterMetaType<PlaylistEnums::PlayOrder>("PlaylistEnums::PlayOrder");

	qmlRegisterType<AudioPlayerEnums>("harbour.sail.player.AudioPlayerState", 1, 0, "AudioPlayerState");
	qRegisterMetaType<AudioPlayerEnums::AudioPlayerState>("AudioPlayerEnums::AudioPlayerState");

	qmlRegisterType<FsHelper>("harbour.sail.player.FsHelper", 1, 0, "FsHelper");
	qmlRegisterType<FsRecordsListModel>("harbour.sail.player.FsRecordsListModel", 1, 0, "FsRecordsListModel");

	qmlRegisterType<LastFmScrobbler>("harbour.sail.player.LastFmError", 1, 0, "LastFmError");
	qRegisterMetaType<LastFmScrobbler::LastFmError>("LastFmScrobbler::LastFmError");

	// Application description / data

	QCoreApplication::setOrganizationName("Alexander Krylkov");
	QCoreApplication::setApplicationName("Sail Player");

	LastFmQueryBuilder::SetApiKey("06b931aaed5fbf1f1558c165f3a08eb4");
	LastFmQueryBuilder::SetSecret("9fe3f69ecd90045d2d18fe6823803370");

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


#include <QApplication>
#include <QtQuick>

#include <sailfishapp.h>

#include "FilesListModel.h"
#include "Artist.h"

int main(int argc, char *argv[])
{
	qmlRegisterType<FilesListModel>("harbour.sail.player.FilesListModel", 1, 0, "FilesListModel");

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

//	QList<Track>* tracks = new QList<Track>();
//	Track track("test", "01", "03:14");
//	tracks->append(track);

	return app->exec();
}

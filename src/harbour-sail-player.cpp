#include <QGuiApplication>
#include <QQuickView>

#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQml>
#include <QTimer>
#include <QTranslator>
#include <QDir>
#include <QScreen>

int main(int argc, char *argv[])
{
	// Initialization

	QScopedPointer<QGuiApplication> app(new QGuiApplication(argc, argv));
	QScopedPointer<QQuickView> view(new QQuickView);

	// Starting up

	//QQuickWindow::setDefaultAlphaBuffer(true);

	view->setSource(QUrl::fromLocalFile("/usr/share/harbour-sail-player/qml/harbour-sail-player.qml"));

	view->showFullScreen();

	return app->exec();
}

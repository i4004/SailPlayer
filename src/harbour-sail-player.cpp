#include <QApplication>
#include <QtQuick>

#include <sailfishapp.h>

int main(int argc, char *argv[])
{
	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

	return app->exec();
}

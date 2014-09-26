#include <QApplication>
#include <QtQuick>

#include <sailfishapp.h>

int main(int argc, char *argv[])
{
//	QGuiApplication *app = application(argc, argv);

//	QQuickWindow::setDefaultAlphaBuffer(true);

//	QScopedPointer<QQuickView> view(new QQuickView);

//	QString path = QString(DEPLOYMENT_PATH);

//	view->setSource(QUrl::fromLocalFile(path + "qml/Main.qml"));
//	view->show();

//	return app->exec();

	return SailfishApp::main(argc, argv);
}

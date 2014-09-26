#include <QApplication>
#include <QtQuick>

int main(int argc, char *argv[])
{
	QScopedPointer<QApplication> app(new QApplication(argc, argv));
	QScopedPointer<QQuickView> view(new QQuickView);

	QString path = QString(DEPLOYMENT_PATH);

	view->setSource(QUrl::fromLocalFile(path + "qml/Main.qml"));
	view->setDefaultAlphaBuffer(true);
	view->showFullScreen();

	return app->exec();
}

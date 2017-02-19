#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "SailPlayerController.hpp"

void SetApplicationDescription()
{
	QCoreApplication::setOrganizationName("Alexander Krylkov");
	QCoreApplication::setApplicationName("Sail Player Dev");
}

int main(int argc, char *argv[])
{
	SetApplicationDescription();

	// Init

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());
	QScopedPointer<SailPlayerController> rootController(new SailPlayerController());

	// Run

	rootController->ExposeComponentsToQml(&(*view));
	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

	return app->exec();
}

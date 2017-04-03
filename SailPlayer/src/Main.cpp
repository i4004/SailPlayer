#include <QtQuick>
#include <sailfishapp.h>

#include "Registrator.hpp"

void SetGlobalApplicationEncoding()
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
}

void SetApplicationDescription()
{
	QCoreApplication::setOrganizationName("Alexander Krylkov");
	QCoreApplication::setApplicationName("Sail Player Dev");
}

int main(int argc, char *argv[])
{
	SetGlobalApplicationEncoding();
	SetApplicationDescription();

	// Init

	QScopedPointer<QGuiApplication> app(SailfishApp::application(argc, argv));
	QScopedPointer<QQuickView> view(SailfishApp::createView());
	QScopedPointer<Registrator> registrator(new Registrator());

	// C++ binding with QML

	Registrator::RegisterQmlTypes();
	registrator->ExposeComponentsToQml(&(*view));

	// Run

	view->setSource(SailfishApp::pathTo("qml/Main.qml"));
	view->show();

	return app->exec();
}

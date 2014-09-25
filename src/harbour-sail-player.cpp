#include <QApplication>
#include <QDeclarativeView>

#include "sailfishapplication.h"

int main(int argc, char *argv[])
{
	QScopedPointer<QApplication> app(Sailfish::createApplication(argc, argv));
	QScopedPointer<QDeclarativeView> view(Sailfish::createView("qml/Main.qml"));

	Sailfish::showView(view.data());

	return app->exec();
}

#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController()
{
}

SailPlayerController::~SailPlayerController()
{
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	Q_UNUSED(view);
}

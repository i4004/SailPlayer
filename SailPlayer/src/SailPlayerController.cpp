#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController()
{
//	_audioResource = new AudioResource();
//	_audioPlayer = new GstAudioPlayer(_audioResource);
}

SailPlayerController::~SailPlayerController()
{
//	delete _audioPlayer;
//	delete _audioResource;
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	Q_UNUSED(view);
}

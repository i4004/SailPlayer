#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController()
{
//	_audioResource = new AudioResource();

	_gstreamerInit = new GInit();
	_pipeline = new GPipeline();
	_bus = new GBus(_pipeline);
	_audioPlayer = new GAudioPlayer(_bus, _pipeline);
}

SailPlayerController::~SailPlayerController()
{
	delete _audioPlayer;
	delete _bus;
	delete _pipeline;
	delete _gstreamerInit;
//	delete _audioResource;
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	Q_UNUSED(view);
}

#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController()
{
//	_audioResource = new AudioResource();

	_gstreamerInit = new GInit();
	_pipeline = new GPipeline();
	_bus = new GBus(_pipeline);
	_equalizer = new GEqualizer();
	_sink = new GAutoSink();
	_pluginsLinkController = new GPlugins(_pipeline, _equalizer, _sink);
	_audioPlayer = new GAudioPlayer(_bus, _pipeline);
}

SailPlayerController::~SailPlayerController()
{
	delete _audioPlayer;
	delete _pluginsLinkController;
	delete _sink;
	delete _equalizer;
	delete _bus;
	delete _pipeline;
	delete _gstreamerInit;
//	delete _audioResource;
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	Q_UNUSED(view);
}

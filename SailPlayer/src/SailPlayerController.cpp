#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController()
{
	_gstreamerInit = new GInit();
	_pipeline = new GPipeline();
	_bus = new GBus(_pipeline);
	_equalizer = new GEqualizer();
	_sink = new GAutoSink();
	_pluginsLinkController = new GPlugins(_pipeline, _equalizer, _sink);
	_audioResource = new AudioResource();
	_audioPlayer = new AudioPlayer(_audioResource, _bus, _pipeline);
}

SailPlayerController::~SailPlayerController()
{
	delete _audioPlayer;
	delete _audioResource;
	delete _pluginsLinkController;
	delete _sink;
	delete _equalizer;
	delete _bus;
	delete _pipeline;
	delete _gstreamerInit;
}

void SailPlayerController::ExposeComponentsToQml(QQuickView* view)
{
	Q_UNUSED(view);
}

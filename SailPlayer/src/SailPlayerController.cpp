#include <QQmlContext>

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController()
{
	// Audio

	_gstreamerInit = new GInit();
	_pipeline = new GPipeline();
	_bus = new GBus(_pipeline);
	_equalizer = new GEqualizer();
	_sink = new GAutoSink();
	_pluginsLinkController = new GPlugins(_pipeline, _equalizer, _sink);
	_audioResource = new AudioResource();
	_audioPlayer = new AudioPlayer(_audioResource, _bus, _pipeline);

	// Factories

	_playlistFactory = new PlaylistFactory();

	// Database

	_dbConnectionManager = new SailPlayerConnectionManager();

	// Core controllers

	_playlistsController = new PlaylistsController(&_playlistsModel, _playlistFactory);
}

SailPlayerController::~SailPlayerController()
{
	// Core controllers

	delete _playlistsController;

	// Database

	delete _dbConnectionManager;

	// Factories

	delete _playlistFactory;

	// Audio

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
	view->rootContext()->setContextProperty("playlistsModel", &_playlistsModel);
	view->rootContext()->setContextProperty("playlistsController", _playlistsController);

//	_pipeline->SetFileToPlay("/home/nemo/Music/Ringtones/Biosfear.flac");
//	_audioPlayer->Play();
}

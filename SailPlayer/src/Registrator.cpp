#include <QQmlContext>

#include "Registrator.hpp"

Registrator::Registrator()
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

	// Database

	_dbConnectionManager = new SailPlayerConnectionManager();

	// Playlists

	_playlistFactory = new PlaylistFactory();
	_playlistsRepository = new PlaylistsRepository(_dbConnectionManager->GetConnection(), _playlistFactory);
	_playlistsControllerFactory = new PlaylistsControllerFactory(_playlistsRepository, _playlistFactory);
}

Registrator::~Registrator()
{
	// Playlists

	delete _playlistsControllerFactory;
	delete _playlistsRepository;
	delete _playlistFactory;

	// Database

	delete _dbConnectionManager;

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

void Registrator::RegisterQmlTypes()
{
	qmlRegisterUncreatableType<PlaylistsController>("harbour.sail.player.PlaylistsController", 1, 0, "PlaylistsController*", "PlaylistsController is uncreatable type");
}

void Registrator::ExposeComponentsToQml(QQuickView* view)
{
	view->rootContext()->setContextProperty("spState", &_state);
	view->rootContext()->setContextProperty("playlistsControllerFactory", _playlistsControllerFactory);
}

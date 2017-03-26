#include <QQmlContext>

#include "Settings/SettingsController.hpp"
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
	_playlistController = new PlaylistController(&_playlistModel);
	_playlistsController = new PlaylistsController(&_playlistsModel, _playlistsRepository, _playlistFactory);

	_sailPlayerController = new SettingsController(&_settings, &_state, _playlistsController);
}

Registrator::~Registrator()
{
	delete _sailPlayerController;

	// Playlists

	delete _playlistsController;
	delete _playlistController;
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

void Registrator::ExposeComponentsToQml(QQuickView* view)
{
	view->rootContext()->setContextProperty("spState", &_state);
	view->rootContext()->setContextProperty("playlistModel", &_playlistModel);
	view->rootContext()->setContextProperty("playlistsModel", &_playlistsModel);
	view->rootContext()->setContextProperty("spController", _sailPlayerController);

//	_pipeline->SetFileToPlay("/home/nemo/Music/Ringtones/Biosfear.flac");
//	_audioPlayer->Play();
}

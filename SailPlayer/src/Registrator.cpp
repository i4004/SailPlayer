#include <QQmlContext>

#include "Registrator.hpp"
#include "State/SailPlayerStateFactory.hpp"

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
	_playlistsRepository = new PlaylistsRepository(_dbConnectionManager->GetConnection(), _playlistFactory);

	// State
	_state = SailPlayerStateFactory(_playlistsRepository, &_settings).Create();

	// IO

	_fsRecordInfoFactory = new FsRecordInfoFactory();
	_fsRecordsListControllerFactory = new FsRecordsListControllerFactory(_fsRecordInfoFactory, _state, &_settings);

	// Playlists

	_playlistFactory = new PlaylistFactory();
	_playlistsControllerFactory = new PlaylistsControllerFactory(_playlistsRepository, _playlistFactory, _state, &_settings);
}

Registrator::~Registrator()
{
	// Playlists

	delete _playlistsControllerFactory;
	delete _playlistFactory;

	// IO

	delete _fsRecordsListControllerFactory;
	delete _fsRecordInfoFactory;

	// State
	delete _state;

	// Database

	delete _playlistsRepository;
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
}

void Registrator::ExposeComponentsToQml(QQuickView* view)
{
	view->rootContext()->setContextProperty("spState", _state);

	view->rootContext()->setContextProperty("fsRecordsListControllerFactory", _fsRecordsListControllerFactory);
	view->rootContext()->setContextProperty("playlistsControllerFactory", _playlistsControllerFactory);
}

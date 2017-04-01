#ifndef REGISTRATOR_HPP
#define REGISTRATOR_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/AudioPlayer.hpp"
#include "Audio/Gst/GInit.hpp"
#include "Audio/Gst/GPlugins.hpp"
#include "Database/SailPlayerConnectionManager.hpp"
#include "Playlists/PlaylistFactory.hpp"
#include "Playlists/PlaylistsController.hpp"
#include "Playlists/PlaylistsControllerFactory.hpp"
#include "Playlists/PlaylistsModel.hpp"
#include "Playlists/PlaylistsRepository.hpp"
#include "Settings/SailPlayerSettings.hpp"
#include "State/SailPlayerState.hpp"

using namespace Audio;
using namespace Audio::Gst;
using namespace Database;
using namespace Playlists;
using namespace Settings;
using namespace State;

class Registrator : public QObject
{
	Q_OBJECT

public:
	Registrator();
	~Registrator();

	static void RegisterQmlTypes();

	void ExposeComponentsToQml(QQuickView* view);

private:
	// Audio

	GInit* _gstreamerInit;
	GPipeline* _pipeline;
	GBus* _bus;
	GEqualizer* _equalizer;
	GAutoSink* _sink;
	GPlugins* _pluginsLinkController;
	AudioResource* _audioResource;
	AudioPlayer* _audioPlayer;

	// Database

	SailPlayerConnectionManager* _dbConnectionManager;

	// Playlists

	PlaylistFactory* _playlistFactory;
	PlaylistsRepository* _playlistsRepository;
	PlaylistsControllerFactory* _playlistsControllerFactory;

	SailPlayerState _state;

	SailPlayerSettings _settings;
};

#endif // REGISTRATOR_HPP

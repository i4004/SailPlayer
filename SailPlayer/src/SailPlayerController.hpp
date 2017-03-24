#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/AudioPlayer.hpp"
#include "Audio/Gst/GInit.hpp"
#include "Audio/Gst/GPlugins.hpp"
#include "Database/SailPlayerConnectionManager.hpp"
#include "Playlists/PlaylistController.hpp"
#include "Playlists/PlaylistFactory.hpp"
#include "Playlists/PlaylistModel.hpp"
#include "Playlists/PlaylistsController.hpp"
#include "Playlists/PlaylistsModel.hpp"
#include "Playlists/PlaylistsRepository.hpp"

using namespace Audio;
using namespace Audio::Gst;
using namespace Database;
using namespace Playlists;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController();
	~SailPlayerController();

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

	PlaylistsModel _playlistsModel;
	PlaylistModel _playlistModel;
	PlaylistFactory* _playlistFactory;
	PlaylistsRepository* _playlistsRepository;
	PlaylistController* _playlistController;
	PlaylistsController* _playlistsController;
};

#endif // SAILPLAYERCONTROLLER_HPP

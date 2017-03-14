#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/AudioPlayer.hpp"
#include "Audio/Gst/GInit.hpp"
#include "Audio/Gst/GPlugins.hpp"
#include "Controllers/PlaylistsController.hpp"
#include "Database/Repositories/PlaylistsRepository.hpp"
#include "Database/SailPlayerConnectionManager.hpp"
#include "Model/PlaylistsModel.hpp"
#include "Tracks/PlaylistFactory.hpp"

using namespace Audio;
using namespace Audio::Gst;
using namespace Controllers;
using namespace Database;
using namespace Database::Repositories;
using namespace Model;

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

	// Models

	PlaylistsModel _playlistsModel;

	// Factories

	PlaylistFactory* _playlistFactory;

	// Database

	SailPlayerConnectionManager* _dbConnectionManager;
	PlaylistsRepository* _playlistsRepository;

	// Core controllers

	PlaylistsController* _playlistsController;
};

#endif // SAILPLAYERCONTROLLER_HPP

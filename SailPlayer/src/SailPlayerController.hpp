#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/AudioPlayer.hpp"
#include "Audio/Gst/GInit.hpp"
#include "Audio/Gst/GPlugins.hpp"
#include "Model/PlaylistsModel.hpp"
#include "PlaylistsController.hpp"

using namespace Audio;
using namespace Audio::Gst;
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

	// Core controllers

	PlaylistsController* _playlistsController;

};

#endif // SAILPLAYERCONTROLLER_HPP

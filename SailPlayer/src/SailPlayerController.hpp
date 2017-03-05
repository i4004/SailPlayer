#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/Gst/GInit.hpp"
#include "Audio/Gst/GPlugins.hpp"
#include "Audio/AudioPlayer.hpp"

using namespace Audio;
using namespace Audio::Gst;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController();
	~SailPlayerController();

	void ExposeComponentsToQml(QQuickView* view);

private:
	GInit* _gstreamerInit;
	GPipeline* _pipeline;
	GBus* _bus;
	GEqualizer* _equalizer;
	GAutoSink* _sink;
	GPlugins* _pluginsLinkController;
	AudioResource* _audioResource;
	AudioPlayer* _audioPlayer;
};

#endif // SAILPLAYERCONTROLLER_HPP

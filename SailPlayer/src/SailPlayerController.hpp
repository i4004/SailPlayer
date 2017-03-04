#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/Gst/GAudioPlayer.hpp"

using namespace Audio::Gst;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController();
	~SailPlayerController();

	void ExposeComponentsToQml(QQuickView* view);

private:
//	AudioResource* _audioResource;
	GBus* _bus;
	GPipeline* _pipeline;
	GAudioPlayer* _audioPlayer;
};

#endif // SAILPLAYERCONTROLLER_HPP

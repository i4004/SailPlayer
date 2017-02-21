#ifndef SAILPLAYERCONTROLLER_HPP
#define SAILPLAYERCONTROLLER_HPP

#include <QObject>
#include <QQuickView>

#include "Audio/AudioPlayer.hpp"

using namespace Audio;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController();
	~SailPlayerController();

	void ExposeComponentsToQml(QQuickView* view);

private:
	AudioResource* _audioResource;
	AudioPlayer* _audioPlayer;
};

#endif // SAILPLAYERCONTROLLER_HPP

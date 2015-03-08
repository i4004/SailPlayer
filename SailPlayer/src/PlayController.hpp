#ifndef PLAYCONTROLLER_HPP
#define PLAYCONTROLLER_HPP

#include <QObject>

#include "Audio/AudioPlayer.hpp"
#include "Models/PlaylistModel.hpp"

using namespace Audio;
using namespace Models;

class PlayController : public QObject
{
	Q_OBJECT

public:
	PlayController(AudioPlayer& player, PlaylistModel& playlist);
	~PlayController();

	Q_INVOKABLE void playPause();
	Q_INVOKABLE void previous();
	Q_INVOKABLE void playTrack(int trackIndex);
	Q_INVOKABLE void next();

private:
	AudioPlayer& _player;
	PlaylistModel& _playlist;
};

#endif // PLAYCONTROLLER_HPP

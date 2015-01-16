#include "AudioPlayer.h"

namespace UI
{
	AudioPlayer::AudioPlayer()
	{
		_player = new QMediaPlayer();
	}

	AudioPlayer::~AudioPlayer()
	{
		delete _player;
	}

	void AudioPlayer::play()
	{
//		_player->setMedia(QUrl::fromLocalFile("/home/nemo/Music/Ringtones/01 - Pull Me Under.mp3"));
		//	player->setVolume(50);
//		_player->play();
	}
}

////	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

//	QList<Track>* tracks = new QList<Track>();
//	Track track("test", "01", "03:14");
//	tracks->append(track);

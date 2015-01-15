#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QtMultimedia/QMediaPlayer>

namespace UI
{
	class AudioPlayer : public QObject
	{
		Q_OBJECT

	public:
		AudioPlayer();
		~AudioPlayer();

		Q_INVOKABLE void play();

	private:
		QMediaPlayer* _player;
	};
}

#endif // AUDIOPLAYER_H

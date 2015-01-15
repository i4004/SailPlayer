#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>

namespace UI
{
	class AudioPlayer : public QObject
	{
		Q_OBJECT

	public:
		AudioPlayer();

		Q_INVOKABLE void play();
	};
}

#endif // AUDIOPLAYER_H

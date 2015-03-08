#ifndef AUDIOPLAYERENUMS_HPP
#define AUDIOPLAYERENUMS_HPP

#include <QObject>

namespace Audio
{
	class AudioPlayerEnums : public QObject
	{
		Q_OBJECT
		Q_ENUMS(AudioPlayerState)

	public:

		enum AudioPlayerState
		{
			Ready = 0,
			Paused = 1,
			Playing = 2
		};
	};
}

#endif // AUDIOPLAYERENUMS_HPP

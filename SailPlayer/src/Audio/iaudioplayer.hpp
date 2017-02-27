#ifndef IAUDIOPLAYER_HPP
#define IAUDIOPLAYER_HPP

#include "AudioPlayerEnums.hpp"

namespace Audio
{
	class IAudioPlayer : public QObject
	{
		Q_OBJECT

	public:
		virtual void Play() = 0;
		virtual void Pause() = 0;
		virtual void Stop() = 0;

	protected:
		AudioPlayerEnums::AudioPlayerState _currentState;
	};
}

#endif // IAUDIOPLAYER_HPP

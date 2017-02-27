#ifndef AUDIOPLAYERBASE_H
#define AUDIOPLAYERBASE_H

#include "IAudioPlayer.hpp"

namespace Audio
{
	class AudioPlayerBase : public IAudioPlayer
	{
		Q_OBJECT
		Q_PROPERTY(Audio::AudioPlayerEnums::AudioPlayerState state READ GetCurrentState NOTIFY StateChanged)

	public:
		AudioPlayerBase();

		virtual void Play();
		virtual void Pause();
		virtual void Stop();

		AudioPlayerEnums::AudioPlayerState GetCurrentState() { return _currentState; }

	signals:
		void StateChanged(AudioPlayerEnums::AudioPlayerState state);
	};
}

#endif // AUDIOPLAYERBASE_H

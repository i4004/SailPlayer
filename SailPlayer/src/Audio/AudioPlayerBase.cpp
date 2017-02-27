#include "AudioPlayerBase.hpp"

namespace Audio
{
	AudioPlayerBase::AudioPlayerBase()
	{
		_currentState = AudioPlayerEnums::Ready;
	}

	void AudioPlayerBase::Play()
	{
		_currentState = AudioPlayerEnums::Playing;

		emit StateChanged(AudioPlayerEnums::Playing);
	}

	void AudioPlayerBase::Pause()
	{
		_currentState = AudioPlayerEnums::Paused;

		emit StateChanged(AudioPlayerEnums::Paused);
	}

	void AudioPlayerBase::Stop()
	{
		_currentState = AudioPlayerEnums::Ready;

		emit StateChanged(AudioPlayerEnums::Ready);
	}
}

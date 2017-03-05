#include "AudioPlayer.hpp"

namespace Audio
{
	AudioPlayer::AudioPlayer(AudioResource* audioResource, GBus* bus, GPipeline* pipeline):GAudioPlayer(bus, pipeline)
	{
		_audioResource = audioResource;

		//		_pausedByResourceBlock = false;
	}

	AudioPlayer::~AudioPlayer()
	{
		_audioResource->Release();
	}

	void AudioPlayer::Play()
	{
		_audioResource->Acquire();

		GAudioPlayer::Play();
	}

	void AudioPlayer::Pause()
	{
		GAudioPlayer::Pause();

		// TODO: check, needed?

		//		_pausedByResourceBlock = false;
		_audioResource->Release();
	}

	void AudioPlayer::Stop()
	{
		GAudioPlayer::Stop();

		_audioResource->Release();
	}
}

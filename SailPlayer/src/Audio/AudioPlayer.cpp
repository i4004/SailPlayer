#include "AudioPlayer.hpp"

namespace Audio
{
	AudioPlayer::AudioPlayer(AudioResource* audioResource, GBus* bus, GPipeline* pipeline) : GAudioPlayer(bus, pipeline)
	{
		_audioResource = audioResource;

		//		_pausedByResourceBlock = false;
		//		connect(_audioResource, SIGNAL(AquireStateChanged(bool)), this, SLOT(OnAudioResourceAquireStateChanged(bool)));
	}

	AudioPlayer::~AudioPlayer()
	{
		_audioResource->Release();

		if(GetCurrentState() != AudioPlayerEnums::Ready)
			Stop();
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

	//	void AudioPlayerBase::OnAudioResourceAquireStateChanged(bool acquired)
	//	{
	//		if(acquired)
	//		{
	//			if(_currentState == AudioPlayerEnums::Paused && _pausedByResourceBlock)
	//				Play();
	//		}
	//		else if(_currentState == AudioPlayerEnums::Playing)
	//		{
	//			Pause();

	//			_pausedByResourceBlock = true;
	//		}
	//	}
}

#include "glib.h"
#include "AudioResource.hpp"

namespace Audio
{
	AudioResource::AudioResource()
	{
		_audioResourceGotReply = false;
		_audioResourceAcquired = false;
		_isConnected = false;
		_resource = audioresource_init(AUDIO_RESOURCE_MEDIA, OnAudioResourceCallback, this);
	}

	AudioResource::~AudioResource()
	{
		audioresource_free(_resource);
	}

	bool AudioResource::Connect()
	{
		if(_isConnected)
			return _audioResourceAcquired;

		_audioResourceGotReply = false;

		audioresource_acquire(_resource);
		WaitForAnAudioResourceCallback();

		return _audioResourceAcquired;
	}

	bool AudioResource::Disconnect()
	{
		if(!_isConnected)
			return _audioResourceAcquired;

		_audioResourceGotReply = false;

		audioresource_release(_resource);
		WaitForAnAudioResourceCallback();

		return _audioResourceAcquired;
	}

	void AudioResource::SetAcquireState(bool acquired)
	{
		_isConnected = acquired;
		_audioResourceGotReply = true;
		_audioResourceAcquired = acquired;

		emit AquireStateChanged(acquired);
	}

	void AudioResource::WaitForAnAudioResourceCallback()
	{
		while (!_audioResourceGotReply)
		{
			g_main_context_iteration(NULL, false);
			nanosleep(&ResourceWaiter, NULL);
		}
	}

	void AudioResource::OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData)
	{
		Q_UNUSED(audioResource);

		AudioResource* resource = static_cast<AudioResource*>(userData);
		resource->SetAcquireState(acquired);
	}
}

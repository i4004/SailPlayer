#include "glib.h"
#include "AudioResource.h"

namespace Audio
{
	void AudioResource::Init()
	{
		_audioResourceGotReply = false;
		_audioResourceAcquired = false;
		_resource = audioresource_init(AUDIO_RESOURCE_MEDIA, OnAudioResourceCallback, this);
	}

	void AudioResource::Free()
	{
		Release();

		audioresource_free(_resource);
	}

	void AudioResource::WaitForAnAudioResourceCallback()
	{
		 while (!_audioResourceGotReply)
		 {
			 g_main_context_iteration(NULL, false);
			 usleep(1000);
		 }
	}

	bool AudioResource::Acquire()
	{
		_audioResourceGotReply = false;

		audioresource_acquire(_resource);
		WaitForAnAudioResourceCallback();

		return _audioResourceAcquired;
	}

	bool AudioResource::Release()
	{
		_audioResourceGotReply = false;

		audioresource_release(_resource);
		WaitForAnAudioResourceCallback();

		return _audioResourceAcquired;
	}

	void AudioResource::SetAcquireState(bool acquired)
	{
		_audioResourceGotReply = true;
		_audioResourceAcquired = acquired;

		emit OnAquireStateChanged(acquired);
	}

	void AudioResource::OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData)
	{
		Q_UNUSED(audioResource);

		AudioResource* resource = static_cast<AudioResource* >(userData);
		resource->SetAcquireState(acquired);
	}
}

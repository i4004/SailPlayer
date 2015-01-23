#include "AudioResource.h"
#include "glib.h"

namespace Audio
{
	audioresource_t* AudioResource::Resource = NULL;
	bool AudioResource::AudioResourceGotReply = false;
	bool AudioResource::AudioResourceAcquired = false;
	AudioResource::OnResourceStateChangedDelegate AudioResource::OnResourceStateChanged = NULL;

	void AudioResource::Init()
	{
		Resource = audioresource_init(AUDIO_RESOURCE_MEDIA, OnAudioResourceCallback, NULL);
	}

	void AudioResource::Free()
	{
		Release();

		audioresource_free(Resource);
	}

	void AudioResource::OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData)
	{
		Q_UNUSED(audioResource);
		Q_UNUSED(userData);

		AudioResourceGotReply = true;
		AudioResourceAcquired = acquired;

		if(OnResourceStateChanged != NULL)
			OnResourceStateChanged(acquired);
	}

	void AudioResource::WaitForAnAudioResourceCallback()
	{
		 while (!AudioResourceGotReply)
		 {
			 g_main_context_iteration(NULL, false);
			 usleep(1000);
		 }
	}

	bool AudioResource::Acquire()
	{
		AudioResourceGotReply = false;

		audioresource_acquire(Resource);
		WaitForAnAudioResourceCallback();

		return AudioResourceAcquired;
	}

	bool AudioResource::Release()
	{
		AudioResourceGotReply = false;

		audioresource_release(Resource);
		WaitForAnAudioResourceCallback();

		return AudioResourceAcquired;
	}

	void AudioResource::SubscribeToResourceStateChange(OnResourceStateChangedDelegate onResourceStateChanged)
	{
		OnResourceStateChanged = onResourceStateChanged;
	}
}

#include "AudioResource.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Audio
{
	AudioResource::AudioResource()
	{
		_acquired = false;
		_resource = audioresource_init(AUDIO_RESOURCE_MEDIA, OnAudioResourceCallback, this);
	}

	AudioResource::~AudioResource()
	{
		Release();

		audioresource_free(_resource);
	}

	void AudioResource::Acquire()
	{
		if(_acquired)
			return;

		audioresource_acquire(_resource);
	}

	void AudioResource::Release()
	{
		if(!_acquired)
			return;

		audioresource_release(_resource);
	}

	void AudioResource::SetAcquired(bool acquired)
	{
		_acquired = acquired;

		#ifdef QT_DEBUG
		qDebug() << "Acquired: " << QString(acquired);
		#endif

		emit AquiredChanged(acquired);
	}

	void AudioResource::OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData)
	{
		Q_UNUSED(audioResource);

		AudioResource* resource = static_cast<AudioResource*>(userData);
		resource->SetAcquired(acquired);
	}
}

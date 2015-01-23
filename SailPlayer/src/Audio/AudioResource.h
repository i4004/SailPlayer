#ifndef AUDIORRSOIRCE_H
#define AUDIORRSOIRCE_H

#include <QObject>
#include <audioresource.h>

namespace Audio
{
	class AudioResource
	{
		typedef void (*OnResourceStateChangedDelegate)(bool);

	public:
		static void Init();
		static void Free();

		static void OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData);
		static void WaitForAnAudioResourceCallback();

		static bool Acquire();
		static bool Release();

		static void SubscribeToResourceStateChange(OnResourceStateChangedDelegate onResourceStateChanged);

	private:
		static audioresource_t* Resource;
		static bool AudioResourceGotReply;
		static bool AudioResourceAcquired;
		static OnResourceStateChangedDelegate OnResourceStateChanged;
	};
}

#endif // AUDIORRSOIRCE_H

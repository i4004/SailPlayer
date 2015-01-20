#ifndef AUDIORRSOIRCE_H
#define AUDIORRSOIRCE_H

#include <QObject>
#include <audioresource.h>

namespace Audio
{
	class AudioResource
	{
	public:
		static void Init();
		static void Free();

		static void OnAudioResourceCallback(audioresource_t* audioResource, bool aquired, void* userData);
		static void WaitForAnAudioResourceCallback();

		static bool Acquire();
		static bool Release();

	private:
		static audioresource_t* Resource;
		static bool AudioResourceGotReply;
		static bool AudioResourceAcquired;
	};
}

#endif // AUDIORRSOIRCE_H

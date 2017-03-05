#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "Gst/GAudioPlayer.hpp"
#include "AudioResource.hpp"

namespace Audio
{
	using namespace Gst;

	class AudioPlayer : public GAudioPlayer
	{
	public:
		AudioPlayer(AudioResource* audioResource, GBus* bus, GPipeline* pipeline);
		~AudioPlayer();

		void Play();
		void Pause();
		void Stop();

	private:
		AudioResource* _audioResource;

//		bool _pausedByResourceBlock;
	};
}

#endif // AUDIOPLAYER_H

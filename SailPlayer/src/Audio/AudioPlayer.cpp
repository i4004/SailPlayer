#include "AudioPlayer.hpp"

namespace Audio
{
	AudioPlayer::AudioPlayer(AudioResource* audioResource, GBus* bus, GPipeline* pipeline):GAudioPlayer(bus, pipeline)
	{
		_audioResource = audioResource;
	}
}

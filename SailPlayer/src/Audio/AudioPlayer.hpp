#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include "AudioResource.hpp"

namespace Audio
{
	class AudioPlayer
	{
	public:
		AudioPlayer(AudioResource* audioResource);

	private:
		AudioResource* _audioResource;
	};
}

#endif // AUDIOPLAYER_H

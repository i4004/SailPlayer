#include "CueIndex.hpp"

namespace Cue
{
	CueIndex::CueIndex(int number, int minutes, int seconds, int frames)
	{
		_number = number;
		_minutes = minutes;
		_seconds = seconds;
		_frames = frames;
	}
}

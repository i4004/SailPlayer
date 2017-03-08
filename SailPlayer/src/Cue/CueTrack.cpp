#include "CueTrack.hpp"

namespace Cue
{
	CueTrack::CueTrack(int number, CueTrackDataType dataType)
	{
		_number = number;
		_dataType = dataType;
	}

	CueTrack::~CueTrack()
	{
		while (!_indexes.isEmpty())
			delete _indexes.takeFirst();
	}
}

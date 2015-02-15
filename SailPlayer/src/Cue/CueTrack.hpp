#ifndef CUETRACK_HPP
#define CUETRACK_HPP

#include <QString>

#include "CueTrackDataType.hpp"

namespace Cue
{
	class CueTrack
	{
	public:
		CueTrack(int number, CueTrackDataType dataType);

		int GetNumber(){ return _number; }
		CueTrackDataType GetDataType(){ return _dataType; }

	private:
		int _number;
		CueTrackDataType _dataType;
	};
}

#endif // CUETRACK_HPP

#ifndef CUETRACKDATATYPE_HPP
#define CUETRACKDATATYPE_HPP

namespace Cue
{
	namespace TrackDataType
	{
		enum CueTrackDataType
		{
			Undefined = 0,
			Audio = 1,
			Cdg = 2,
			Mode12048 = 3,
			Mode12352 = 4,
			Mode22336 = 5,
			Mode22352 = 6,
			Cdi2336 = 7,
			Cdi2352 = 8
		};
	}
}

#endif // CUETRACKDATATYPE_HPP

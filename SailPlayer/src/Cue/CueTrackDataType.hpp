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
			Mode1_2048 = 3,
			Mode1_2352 = 4,
			Mode2_2336 = 5,
			Mode2_2352 = 6,
			Cdi_2336 = 7,
			Cdi_2352 = 8
		};
	}
}

#endif // CUETRACKDATATYPE_HPP

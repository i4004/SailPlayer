#include "TracksFactory.h"

namespace Playlist
{
	TracksFactory::TracksFactory()
	{
	}

	Track* CreateTrack(QString trackName)
	{
		Track* track = new Track(trackName, NULL);

		return track;
	}
}

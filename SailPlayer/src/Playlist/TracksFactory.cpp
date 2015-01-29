#include "TracksFactory.h"

namespace Playlist
{
	TracksFactory::TracksFactory()
	{
	}

	Track* CreateTrack(QString trackName)
	{
		Track* track = new Track("2", trackName, "12:04" , NULL);

		return track;
	}
}

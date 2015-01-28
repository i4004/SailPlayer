#ifndef PLAYLISTFACTORY_H
#define PLAYLISTFACTORY_H

#include "Track.h"

namespace Playlist
{
	class TracksFactory
	{
	public:
		TracksFactory();

		Track* CreateTrack(QString trackName);
	};
}

#endif // PLAYLISTFACTORY_H

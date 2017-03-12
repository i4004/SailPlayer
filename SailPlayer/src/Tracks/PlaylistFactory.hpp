#ifndef PLAYLISTFACTORY_H
#define PLAYLISTFACTORY_H

#include "Playlist.hpp"

namespace Tracks
{
	class PlaylistFactory
	{
	public:
		Playlist* Create(QString name);
	};
}

#endif // PLAYLISTFACTORY_H

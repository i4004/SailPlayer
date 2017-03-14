#ifndef PLAYLISTFACTORY_H
#define PLAYLISTFACTORY_H

#include "Playlist.hpp"

namespace Playlists
{
	class PlaylistFactory
	{
	public:
		Playlist* Create(QString name);
	};
}

#endif // PLAYLISTFACTORY_H

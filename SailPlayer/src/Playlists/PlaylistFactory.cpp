#include "PlaylistFactory.hpp"

namespace Playlists
{
	Playlist* PlaylistFactory::Create(QString name)
	{
		return new Playlist(name);
	}
}

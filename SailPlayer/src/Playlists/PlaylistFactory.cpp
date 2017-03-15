#include "PlaylistFactory.hpp"

namespace Playlists
{
	Playlist* PlaylistFactory::Create(int id, QString name)
	{
		return new Playlist(id, name);
	}
}

#include "Playlist.hpp"

namespace Playlists
{
	Playlist::Playlist()
		: IdentityObject(-1)
	{
	}

	Playlist::Playlist(int id, const QString& name)
		: IdentityObject(id), _name(name)
	{
	}

	Playlist::Playlist(Playlist& playlist)
		: IdentityObject(playlist), _name(playlist.GetName())
	{
	}
}

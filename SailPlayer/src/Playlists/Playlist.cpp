#include "Playlist.hpp"

namespace Playlists
{
	Playlist::Playlist()
		: IdentityObject(-1)
	{
	}

	Playlist::Playlist(Playlist& playlist)
		: IdentityObject(playlist), _name(playlist.GetName())
	{
	}
}

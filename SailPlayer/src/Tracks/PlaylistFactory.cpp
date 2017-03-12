#include "PlaylistFactory.hpp"

namespace Tracks
{
	Playlist* PlaylistFactory::Create(QString name)
	{
		return new Playlist(name);
	}
}

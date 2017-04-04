#include "PlaylistControllerFactory.hpp"

namespace Playlists
{
	PlaylistControllerFactory::PlaylistControllerFactory()
	{
	}

	QObject* PlaylistControllerFactory::create()
	{
		return new PlaylistController();
	}
}

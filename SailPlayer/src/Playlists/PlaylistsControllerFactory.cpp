#include "PlaylistsControllerFactory.hpp"

namespace Playlists
{
	PlaylistsControllerFactory::PlaylistsControllerFactory(PlaylistsRepository* repository, PlaylistFactory* factory)
		: _repository(repository), _factory(factory)
	{
	}

	PlaylistsControllerFactory::~PlaylistsControllerFactory()
	{
	}

	QObject* PlaylistsControllerFactory::create()
	{
		return new PlaylistsController(_repository, _factory);
	}
}




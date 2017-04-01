#include "PlaylistsControllerFactory.hpp"
#include "StatefulPlaylistsController.hpp"

namespace Playlists
{
	PlaylistsControllerFactory::PlaylistsControllerFactory(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state)
		: _repository(repository), _factory(factory), _state(state)
	{
	}

	PlaylistsControllerFactory::~PlaylistsControllerFactory()
	{
	}

	QObject* PlaylistsControllerFactory::create()
	{
		return new StatefulPlaylistsController(_repository, _factory, _state);
	}
}

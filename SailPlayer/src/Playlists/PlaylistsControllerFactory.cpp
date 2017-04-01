#include "PlaylistsControllerFactory.hpp"
#include "SettingsPlaylistsController.hpp"

namespace Playlists
{
	PlaylistsControllerFactory::PlaylistsControllerFactory(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state, SailPlayerSettings* settings)
		: _repository(repository), _factory(factory), _state(state), _settings(settings)
	{
	}

	PlaylistsControllerFactory::~PlaylistsControllerFactory()
	{
	}

	QObject* PlaylistsControllerFactory::create()
	{
		return new SettingsPlaylistsController(_repository, _factory, _state, _settings);
	}
}

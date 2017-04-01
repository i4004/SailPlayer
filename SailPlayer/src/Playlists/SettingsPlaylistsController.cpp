#include "SettingsPlaylistsController.hpp"

namespace Playlists
{
	SettingsPlaylistsController::SettingsPlaylistsController(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state, SailPlayerSettings* settings)
		: StatefulPlaylistsController(repository, factory,state), _settings(settings)
	{
	}

	void SettingsPlaylistsController::deletePlaylist(int id)
	{
		if(id == _settings->GetActivePlaylistID())
			_settings->SetActivePlaylistID();

		StatefulPlaylistsController::deletePlaylist(id);
	}

	void SettingsPlaylistsController::activatePlaylist(int id)
	{
		StatefulPlaylistsController::activatePlaylist(id);

		_settings->SetActivePlaylistID(id);
	}
}

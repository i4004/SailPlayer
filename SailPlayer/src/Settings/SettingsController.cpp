#include "SettingsController.hpp"

namespace Settings
{
	SettingsController::SettingsController(SailPlayerSettings* settings,
										   SailPlayerState* state,
										   PlaylistsController* playlistsController)
		: StatefulController(state, playlistsController),
		  _settings(settings)
	{
		int id = _settings->GetActivePlaylistID();

		if(id != -1)
			activatePlaylist(id);
	}

	void SettingsController::deletePlaylist(int id)
	{
		if(id == _settings->GetActivePlaylistID())
			_settings->SetActivePlaylistID();

		StatefulController::deletePlaylist(id);
	}

	void SettingsController::activatePlaylist(int id)
	{
		StatefulController::activatePlaylist(id);

		_settings->SetActivePlaylistID(id);
	}
}

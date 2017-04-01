#ifndef SETTINGSPLAYLISTSCONTROLLER_H
#define SETTINGSPLAYLISTSCONTROLLER_H

#include "StatefulPlaylistsController.hpp"
#include "../Settings/SailPlayerSettings.hpp"

using namespace Settings;

namespace Playlists
{
	class SettingsPlaylistsController : public StatefulPlaylistsController
	{
	public:
		SettingsPlaylistsController(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state, SailPlayerSettings* settings);

		void deletePlaylist(int id);
		void activatePlaylist(int playlistID);

	private:
		SailPlayerSettings* _settings;
	};
}

#endif // SETTINGSPLAYLISTSCONTROLLER_H

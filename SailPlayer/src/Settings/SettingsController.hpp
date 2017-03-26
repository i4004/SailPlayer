#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "../State/StatefulController.hpp"
#include "SailPlayerSettings.hpp"

using namespace State;

namespace Settings
{
	class SettingsController : public StatefulController
	{
	public:
		SettingsController(SailPlayerSettings* settings, SailPlayerState* state, PlaylistsController* playlistsController);

		void deletePlaylist(int id);
		void activatePlaylist(int playlistID);

	private:
		SailPlayerSettings* _settings;
	};
}

#endif // SETTINGSCONTROLLER_H

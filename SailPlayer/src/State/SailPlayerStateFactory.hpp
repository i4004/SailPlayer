#ifndef SAILPLAYERSTATEFACTORY_H
#define SAILPLAYERSTATEFACTORY_H

#include "SailPlayerState.hpp"
#include "../Playlists/PlaylistsRepository.hpp"
#include "../Settings/SailPlayerSettings.hpp"

using namespace Settings;

namespace State
{
	class SailPlayerStateFactory
	{
	public:
		SailPlayerStateFactory(PlaylistsRepository* playlistsRepository, SailPlayerSettings* settings);

		SailPlayerState* Create();

	private:
		PlaylistsRepository* _playlistsRepository;
		SailPlayerSettings* _settings;

		void LoadActivePlaylist(SailPlayerState* state);
	};
}

#endif // SAILPLAYERSTATEFACTORY_H

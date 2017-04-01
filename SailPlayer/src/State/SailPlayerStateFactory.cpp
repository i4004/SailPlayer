#include "SailPlayerStateFactory.hpp"

namespace State
{
	SailPlayerStateFactory::SailPlayerStateFactory(PlaylistsRepository* playlistsRepository, SailPlayerSettings* settings)
		: _playlistsRepository(playlistsRepository), _settings(settings)
	{
	}

	SailPlayerState* SailPlayerStateFactory::Create()
	{
		SailPlayerState* state = new SailPlayerState();

		LoadActivePlaylist(state);

		return state;
	}

	void SailPlayerStateFactory::LoadActivePlaylist(SailPlayerState* state)
	{
		int id = _settings->GetActivePlaylistID();

		if(id == -1)
			return;

		Playlist* item = _playlistsRepository->GetItem(id);

		if(!item)
			return;

		state->SetActivePlaylist(*item);

		delete item;
	}
}

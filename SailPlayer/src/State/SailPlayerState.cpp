#include "SailPlayerState.hpp"

namespace State
{
	SailPlayerState::SailPlayerState()
	{
		_activePlaylist = nullptr;
	}

	void SailPlayerState::SetActivePlaylist(Playlist* playlist)
	{
		_activePlaylist = playlist;

		emit ActivePlaylistChanged();
	}

	bool SailPlayerState::GetIsPlaylistActive()
	{
		return _activePlaylist;
	}

	int SailPlayerState::GetActivePlaylistID()
	{
		return _activePlaylist ? _activePlaylist->GetID() : -1;
	}

	QString SailPlayerState::GetActivePlaylistName()
	{
		return _activePlaylist ? _activePlaylist->GetName() : QString();
	}
}

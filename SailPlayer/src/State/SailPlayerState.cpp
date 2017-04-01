#include "SailPlayerState.hpp"

namespace State
{
	SailPlayerState::SailPlayerState()
	{
	}

	void SailPlayerState::SetActivePlaylist(Playlist playlist)
	{
		_activePlaylist = playlist;

		emit ActivePlaylistChanged();
	}

	void SailPlayerState::RemoveActivePlaylist()
	{
		Playlist item;
		SetActivePlaylist(item);
	}

	bool SailPlayerState::IsPlaylistActive()
	{
		return _activePlaylist.GetID() != -1;
	}

	int SailPlayerState::GetActivePlaylistID()
	{
		return _activePlaylist.GetID();
	}

	QString SailPlayerState::GetActivePlaylistName()
	{
		return _activePlaylist.GetName();
	}
}

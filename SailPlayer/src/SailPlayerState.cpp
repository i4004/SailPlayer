#include "SailPlayerState.hpp"

SailPlayerState::SailPlayerState()
{
	_activePlaylist = NULL;
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

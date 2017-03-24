#include "SailPlayerState.hpp"

SailPlayerState::SailPlayerState()
{
	_activePlaylist = NULL;
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

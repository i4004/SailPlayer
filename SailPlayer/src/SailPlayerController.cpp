#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(PlaylistsController* playlistsController)
	: _playlistsController(playlistsController)
{
}

void SailPlayerController::renamePlaylist(int id, QString name)
{
	_playlistsController->renamePlaylist(id, name);
}

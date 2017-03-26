#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(PlaylistsController* playlistsController)
	: _playlistsController(playlistsController)
{
}

void SailPlayerController::createPlaylist(QString name)
{
	_playlistsController->CreatePlaylist(name);
}

void SailPlayerController::renamePlaylist(int id, QString name)
{
	_playlistsController->RenamePlaylist(id, name);
}

void SailPlayerController::deletePlaylist(int id)
{
	_playlistsController->DeletePlaylist(id);
}

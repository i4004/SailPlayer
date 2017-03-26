#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(SailPlayerState* state, PlaylistsController* playlistsController)
	: _state(state), _playlistsController(playlistsController)
{
}

void SailPlayerController::renamePlaylist(int id, QString name)
{
	_playlistsController->renamePlaylist(id, name);

	if(id == _state->GetActivePlaylistID())
		emit _state->ActivePlaylistChanged();
}

void SailPlayerController::activatePlaylist(int playlistID)
{
	Playlist* item = _playlistsController->GetPlaylist(playlistID);

	if(!item)
		qFatal("Playlist not found, playlist id: '%s'", QString(playlistID).toUtf8().constData());

	_state->SetActivePlaylist(item);
}

#include "SailPlayerController.hpp"

SailPlayerController::SailPlayerController(SailPlayerState* state, PlaylistsController* playlistsController)
	: _state(state), _playlistsController(playlistsController)
{
}

void SailPlayerController::activatePlaylist(int playlistID)
{
	Playlist* item = _playlistsController->GetPlaylist(playlistID);

	if(!item)
		qFatal("Playlist not found, playlsit id: '%s'", QString(playlistID).toUtf8().constData());

	_state->SetActivePlaylist(item);
}

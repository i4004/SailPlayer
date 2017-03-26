#include "StatefulController.hpp"

StatefulController::StatefulController(SailPlayerState* state, PlaylistsController* playlistsController)
	: SailPlayerController(playlistsController), _state(state), _playlistsController(playlistsController)
{
}

void StatefulController::renamePlaylist(int id, QString name)
{
	SailPlayerController::renamePlaylist(id, name);

	if(id == _state->GetActivePlaylistID())
		emit _state->ActivePlaylistChanged();
}

void StatefulController::activatePlaylist(int playlistID)
{
	Playlist* item = _playlistsController->GetPlaylist(playlistID);

	if(!item)
		qFatal("Playlist not found, playlist id: '%s'", QString(playlistID).toUtf8().constData());

	_state->SetActivePlaylist(item);
}

#include "StatefulController.hpp"

namespace State
{
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

	void StatefulController::deletePlaylist(int id)
	{
		if(id == _state->GetActivePlaylistID())
		{
			_state->SetActivePlaylist();
			emit _state->ActivePlaylistChanged();
		}

		SailPlayerController::deletePlaylist(id);
	}

	void StatefulController::activatePlaylist(int id)
	{
		Playlist* item = _playlistsController->GetPlaylist(id);

		if(!item)
			qFatal("Playlist not found, id: '%s'", QString(id).toUtf8().constData());

		_state->SetActivePlaylist(item);
	}
}

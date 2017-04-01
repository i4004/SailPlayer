#include "StatefulPlaylistsController.hpp"

namespace Playlists
{
	StatefulPlaylistsController::StatefulPlaylistsController(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state)
		: PlaylistsController(repository, factory), _repository(repository), _state(state)
	{
	}

	void StatefulPlaylistsController::renamePlaylist(int id, QString name)
	{
		PlaylistsController::renamePlaylist(id, name);

		if(id == _state->GetActivePlaylistID())
		{
			activatePlaylist(id);
			emit _state->ActivePlaylistChanged();
		}
	}

	void StatefulPlaylistsController::deletePlaylist(int id)
	{
		if(id == _state->GetActivePlaylistID())
		{
			_state->RemoveActivePlaylist();
			emit _state->ActivePlaylistChanged();
		}

		PlaylistsController::deletePlaylist(id);
	}

	void StatefulPlaylistsController::activatePlaylist(int id)
	{
		Playlist* item = _repository->GetItem(id);

		if(!item)
			qFatal("Playlist not found, id: '%s'", QString(id).toUtf8().constData());

		_state->SetActivePlaylist(*item);

		delete item;
	}
}

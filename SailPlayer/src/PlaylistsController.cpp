#include "PlaylistsController.hpp"

PlaylistsController::PlaylistsController(PlaylistsModel* model)
	: _model(model)
{
}

void PlaylistsController::deletePlaylist(int playlistIndex)
{
	_model->DeleteItem(playlistIndex);
}


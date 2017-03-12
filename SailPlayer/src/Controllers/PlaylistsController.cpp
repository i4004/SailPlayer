#include "PlaylistsController.hpp"

namespace Controllers
{
	PlaylistsController::PlaylistsController(PlaylistsModel* model, PlaylistFactory* factory)
		: _model(model), _factory(factory)
	{
	}

	void PlaylistsController::createPlaylist(QString name)
	{
		_model->AddItem(_factory->Create(name));
	}

	void PlaylistsController::deletePlaylist(int playlistIndex)
	{
		_model->DeleteItem(playlistIndex);
	}
}

#include "PlaylistsController.hpp"

namespace Playlists
{
	PlaylistsController::PlaylistsController(PlaylistsModel* model, PlaylistsRepository* repository, PlaylistFactory* factory)
		: _model(model), _repository(repository), _factory(factory)
	{
		_model->AddItems(_repository->GetItems());
	}

	void PlaylistsController::createPlaylist(QString name)
	{
		_model->AddItem(_factory->Create(_repository->AddItem(name), name));
	}

	void PlaylistsController::deletePlaylist(int id)
	{
		_repository->DeleteItem(id);
		_model->DeleteItemByID(id);
	}
}

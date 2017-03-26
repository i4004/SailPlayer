#include "PlaylistsController.hpp"

namespace Playlists
{
	PlaylistsController::PlaylistsController(PlaylistsModel* model, PlaylistsRepository* repository, PlaylistFactory* factory)
		: _model(model), _repository(repository), _factory(factory)
	{
		_model->AddItems(_repository->GetItems());
	}

	void PlaylistsController::CreatePlaylist(QString name)
	{
		_model->AddItem(_factory->Create(_repository->AddItem(name), name));
	}

	Playlist* PlaylistsController::GetPlaylist(int id)
	{
		return _model->GetItem(id);
	}

	void PlaylistsController::RenamePlaylist(int id, QString name)
	{
		_repository->UpdateItem(id, name);
		_model->RenameItem(id, name);
	}

	void PlaylistsController::DeletePlaylist(int id)
	{
		_repository->DeleteItem(id);
		_model->DeleteItemByID(id);
	}
}

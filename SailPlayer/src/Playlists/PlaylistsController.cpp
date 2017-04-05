#include "PlaylistsController.hpp"

#include <QQmlEngine>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Playlists
{
	PlaylistsController::PlaylistsController(PlaylistsRepository* repository, PlaylistFactory* factory)
		: _repository(repository), _factory(factory)
	{
		QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

		#ifdef QT_DEBUG
		qDebug() << "Construction";
		#endif

		_model = new PlaylistsModel(this);

		_model->AddItems(_repository->GetItems());
	}

	PlaylistsController::~PlaylistsController()
	{
		#ifdef QT_DEBUG
		qDebug() << "Destruction";
		#endif
	}

	void PlaylistsController::createPlaylist(QString name)
	{
		Playlist* item = _factory->Create(name);

		_repository->AddItem(item);

		_model->AddItem(item);
	}

	void PlaylistsController::renamePlaylist(int id, QString name)
	{
		Playlist* item = _model->GetItem(id);

		item->SetName(name);

		_repository->UpdateItem(item);
		_model->RefreshItem(item);
	}

	void PlaylistsController::deletePlaylist(int id)
	{
		Playlist* item = _model->GetItem(id);

		_repository->DeleteItem(item);
		_model->DeleteItem(item);
	}
}

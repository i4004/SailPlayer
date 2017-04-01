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
		_model->AddItem(_factory->Create(_repository->AddItem(name), name));
	}

//	Playlist* PlaylistsController::GetPlaylist(int id)
//	{
//		return _model->GetItem(id);
//	}

	void PlaylistsController::renamePlaylist(int id, QString name)
	{
		_repository->UpdateItem(id, name);
		_model->RenameItem(id, name);
	}

	void PlaylistsController::deletePlaylist(int id)
	{
		_repository->DeleteItem(id);
		_model->DeleteItemByID(id);
	}
}

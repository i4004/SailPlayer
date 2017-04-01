#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

#include <QObject>

#include "PlaylistFactory.hpp"
#include "PlaylistsModel.hpp"
#include "PlaylistsRepository.hpp"

using namespace Model;

namespace Playlists
{
	class PlaylistsController : public QObject
	{
		Q_OBJECT

	public:
		PlaylistsController(PlaylistsRepository* repository, PlaylistFactory* factory);
		~PlaylistsController();

		Q_INVOKABLE virtual void createPlaylist(QString name);
		Q_INVOKABLE virtual void renamePlaylist(int id, QString name);
		Q_INVOKABLE virtual void deletePlaylist(int id);
		Q_INVOKABLE virtual void activatePlaylist(int id) { Q_UNUSED(id); }

		Q_INVOKABLE QObject* getModel() { return _model; }

	private:
		PlaylistsModel* _model;
		PlaylistsRepository* _repository;
		PlaylistFactory* _factory;
	};
}

#endif // PLAYLISTSCONTROLLER_H

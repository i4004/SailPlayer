#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

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
		PlaylistsController(PlaylistsModel* model, PlaylistsRepository* repository, PlaylistFactory* factory);

		Q_INVOKABLE void createPlaylist(QString name);
		Playlist* GetPlaylist(int id);
		Q_INVOKABLE void renamePlaylist(int id, QString name);
		Q_INVOKABLE void deletePlaylist(int id);

	private:
		PlaylistsModel* _model;
		PlaylistsRepository* _repository;
		PlaylistFactory* _factory;
	};
}

#endif // PLAYLISTSCONTROLLER_H

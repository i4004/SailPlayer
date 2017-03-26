#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

#include "PlaylistFactory.hpp"
#include "PlaylistsModel.hpp"
#include "PlaylistsRepository.hpp"

using namespace Model;

namespace Playlists
{
	class PlaylistsController
	{
	public:
		PlaylistsController(PlaylistsModel* model, PlaylistsRepository* repository, PlaylistFactory* factory);

		void CreatePlaylist(QString name);
		Playlist* GetPlaylist(int id);
		void RenamePlaylist(int id, QString name);
		void DeletePlaylist(int id);

	private:
		PlaylistsModel* _model;
		PlaylistsRepository* _repository;
		PlaylistFactory* _factory;
	};
}

#endif // PLAYLISTSCONTROLLER_H

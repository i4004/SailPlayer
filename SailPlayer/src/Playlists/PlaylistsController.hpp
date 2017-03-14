#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

#include "PlaylistFactory.hpp"
#include "PlaylistsModel.hpp"

using namespace Model;

namespace Playlists
{
	class PlaylistsController : public QObject
	{
		Q_OBJECT

	public:
		PlaylistsController(PlaylistsModel* model, PlaylistFactory* factory);

		Q_INVOKABLE void createPlaylist(QString name);
		Q_INVOKABLE void deletePlaylist(int playlistIndex);

	private:
		PlaylistsModel* _model;
		PlaylistFactory* _factory;
	};
}

#endif // PLAYLISTSCONTROLLER_H

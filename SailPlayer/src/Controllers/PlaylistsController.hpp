#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

#include "../Model/PlaylistsModel.hpp"
#include "../Tracks/PlaylistFactory.hpp"

using namespace Model;

namespace Controllers
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

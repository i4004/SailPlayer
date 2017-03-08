#ifndef PLAYLISTSCONTROLLER_H
#define PLAYLISTSCONTROLLER_H

#include "Model/PlaylistsModel.hpp"

using namespace Model;

class PlaylistsController : public QObject
{
	Q_OBJECT

public:
	PlaylistsController(PlaylistsModel* model);

	Q_INVOKABLE void deletePlaylist(int playlistIndex);

private:
	PlaylistsModel* _model;
};

#endif // PLAYLISTSCONTROLLER_H

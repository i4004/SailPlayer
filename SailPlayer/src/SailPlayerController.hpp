#ifndef SAILPLAYERCONTROLLER_H
#define SAILPLAYERCONTROLLER_H

#include "Playlists/PlaylistsController.hpp"

using namespace Playlists;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController(PlaylistsController* playlistsController);

	Q_INVOKABLE virtual void createPlaylist(QString name);
	Q_INVOKABLE virtual void renamePlaylist(int id, QString name);
	Q_INVOKABLE virtual void deletePlaylist(int id);
	Q_INVOKABLE virtual void activatePlaylist(int playlistID) = 0;

private:
	PlaylistsController* _playlistsController;
};

#endif // SAILPLAYERCONTROLLER_H

#ifndef SAILPLAYERCONTROLLER_H
#define SAILPLAYERCONTROLLER_H

#include "Playlists/PlaylistsController.hpp"
#include "SailPlayerState.hpp"

using namespace Playlists;

class SailPlayerController : public QObject
{
	Q_OBJECT

public:
	SailPlayerController(SailPlayerState* state, PlaylistsController* playlistsController);

	Q_INVOKABLE void renamePlaylist(int id, QString name);
	Q_INVOKABLE void activatePlaylist(int playlistID);

private:
	SailPlayerState* _state;
	PlaylistsController* _playlistsController;
};

#endif // SAILPLAYERCONTROLLER_H

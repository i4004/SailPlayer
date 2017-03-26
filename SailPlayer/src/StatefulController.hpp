#ifndef STATEFULCONTROLLER_H
#define STATEFULCONTROLLER_H

#include "SailPlayerController.hpp"

class StatefulController : public SailPlayerController
{
public:
	StatefulController(SailPlayerState* state, PlaylistsController* playlistsController);

	void renamePlaylist(int id, QString name);
	void activatePlaylist(int playlistID);

private:
	SailPlayerState* _state;
	PlaylistsController* _playlistsController;
};

#endif // STATEFULCONTROLLER_H

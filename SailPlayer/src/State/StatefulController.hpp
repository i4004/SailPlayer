#ifndef STATEFULCONTROLLER_H
#define STATEFULCONTROLLER_H

#include "../SailPlayerController.hpp"
#include "SailPlayerState.hpp"

namespace State
{
	class StatefulController : public SailPlayerController
	{
	public:
		StatefulController(SailPlayerState* state, PlaylistsController* playlistsController);

		void renamePlaylist(int id, QString name);
		void deletePlaylist(int id);
		void activatePlaylist(int id);

	private:
		SailPlayerState* _state;
		PlaylistsController* _playlistsController;
	};
}

#endif // STATEFULCONTROLLER_H

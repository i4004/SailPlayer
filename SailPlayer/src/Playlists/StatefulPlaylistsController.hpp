#ifndef STATEFULPLAYLISTSCONTROLLER_H
#define STATEFULPLAYLISTSCONTROLLER_H

#include "PlaylistsController.hpp"
#include "../State/SailPlayerState.hpp"

using namespace State;

namespace Playlists
{
	class StatefulPlaylistsController : public PlaylistsController
	{
	public:
		StatefulPlaylistsController(PlaylistsRepository* repository, PlaylistFactory* factory, SailPlayerState* state);

		void renamePlaylist(int id, QString name);
		void deletePlaylist(int id);
		void activatePlaylist(int id);

	private:
		PlaylistsRepository* _repository;
		SailPlayerState* _state;
	};
}

#endif // STATEFULPLAYLISTSCONTROLLER_H

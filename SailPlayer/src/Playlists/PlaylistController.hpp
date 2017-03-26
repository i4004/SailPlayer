#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H

#include "PlaylistModel.hpp"

namespace Playlists
{
	class PlaylistController
	{
	public:
		PlaylistController(PlaylistModel* model);

	private:
		PlaylistModel* _model;
	};
}

#endif // PLAYLISTCONTROLLER_H

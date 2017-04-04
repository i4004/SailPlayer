#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H

#include "PlaylistModel.hpp"

namespace Playlists
{
	class PlaylistController : public QObject
	{
		Q_OBJECT

	public:
		PlaylistController();

		Q_INVOKABLE QObject* getModel() { return _model; }

	private:
		PlaylistModel* _model;
	};
}

#endif // PLAYLISTCONTROLLER_H

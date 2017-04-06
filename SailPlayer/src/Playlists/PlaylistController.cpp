#include "PlaylistController.hpp"

#include <QQmlEngine>

namespace Playlists
{
	PlaylistController::PlaylistController()
	{
		QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

		_model = new PlaylistModel(this);
	}

	void PlaylistController::loadTracks(ITracksLoader* loader)
	{
		_model->AddItems(loader->Build());
	}
}
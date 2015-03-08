#include "PlaylistController.hpp"

namespace Playlist
{
	PlaylistController::PlaylistController(PlaylistModel& playlist) : _playlist(playlist)
	{
		_tracksLoader = new TracksLoader(_tracksFactory, _filesFactory);
	}

	PlaylistController::~PlaylistController()
	{
		delete _tracksLoader;
	}

	void PlaylistController::addTracksFromPath(QString directoryPath)
	{
		_filesFactory.SetDirectoryPath(directoryPath);
		_playlist.AddTracks(_tracksLoader->Build());
	}
}

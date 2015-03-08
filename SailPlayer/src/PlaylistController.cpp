#include "PlaylistController.hpp"

namespace Playlist
{
	PlaylistController::PlaylistController(PlaylistModel& playlist, SailPlayerSettings& settings) : _playlist(playlist), _settings(settings)
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

		_settings.SetPlaylist(_playlist.GetTracks());
	}

	void PlaylistController::clear()
	{
		_playlist.Clear();

		_settings.SetPlaylist(_playlist.GetTracks());
	}
}

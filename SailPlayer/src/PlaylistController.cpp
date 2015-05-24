#include "PlaylistController.hpp"

#ifdef _DEBUG
#include <QDebug>
#endif

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
		#ifdef _DEBUG
		qDebug() << "Begin";
		#endif

		_filesFactory.SetDirectoryPath(directoryPath);
		_playlist.AddTracks(_tracksLoader->Build());

		_settings.SetPlaylist(_playlist.GetTracks());

		#ifdef _DEBUG
		qDebug() << "End";
		#endif
	}

	void PlaylistController::clear()
	{
		#ifdef _DEBUG
		qDebug() << "Begin";
		#endif

		_playlist.Clear();

		_settings.SetPlaylist(_playlist.GetTracks());

		#ifdef _DEBUG
		qDebug() << "End";
		#endif
	}
}

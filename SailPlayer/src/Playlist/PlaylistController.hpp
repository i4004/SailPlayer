#ifndef PLAYLISTCONTROLLER_HPP
#define PLAYLISTCONTROLLER_HPP

#include "../Models/PlaylistModel.hpp"
#include "DirectoryRecursiveMultimediaFilesListFactory.hpp"
#include "TracksFactory.hpp"
#include "TracksLoader.hpp"

using namespace Models;

namespace Playlist
{
	class PlaylistController : public QObject
	{
		Q_OBJECT

	public:
		PlaylistController(PlaylistModel& playlist);
		~PlaylistController();

		Q_INVOKABLE void addTracksFromPath(QString directoryPath);

	private:
		PlaylistModel& _playlist;

		ITracksLoader* _tracksLoader;

		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;
	};
}

#endif // PLAYLISTCONTROLLER_HPP

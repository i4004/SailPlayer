#ifndef PLAYLISTCONTROLLER_HPP
#define PLAYLISTCONTROLLER_HPP

#include "Models/PlaylistModel.hpp"
#include "SailPlayerSettings.hpp"
#include "Playlist/DirectoryRecursiveMultimediaFilesListFactory.hpp"
#include "Playlist/TracksFactory.hpp"
#include "Playlist/TracksLoader.hpp"

using namespace Models;

namespace Playlist
{
	class PlaylistController : public QObject
	{
		Q_OBJECT

	public:
		PlaylistController(PlaylistModel& playlist, SailPlayerSettings& settings);
		~PlaylistController();

		Q_INVOKABLE void addTracksFromPath(QString directoryPath);
		Q_INVOKABLE void clear();

	private:
		PlaylistModel& _playlist;
		SailPlayerSettings& _settings;

		ITracksLoader* _tracksLoader;

		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;
	};
}

#endif // PLAYLISTCONTROLLER_HPP

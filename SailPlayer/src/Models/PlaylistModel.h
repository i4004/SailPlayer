#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include "../Playlist/TracksLoader.h"
#include "../Playlist/DirectoryRecursiveMultimediaFilesListFactory.h"
#include "../Playlist/TracksFactory.h"
#include "../SailPlayerSettings.h"
#include "PlaylistModelBase.h"

namespace Models
{
	class PlaylistModel : public PlaylistModelBase
	{
		Q_OBJECT

	public:
		explicit PlaylistModel(QObject* parent = 0);
		~PlaylistModel();

		// Playlist controls

		Q_INVOKABLE void addTracks(QString directoryPath);

		Q_INVOKABLE void clearPlaylist();

		// Load playlist from settings
		Q_INVOKABLE void loadPlaylist();

		// Save playlist to settings
		Q_INVOKABLE void savePlaylist();

		Q_INVOKABLE void toggleSelectTrack(int itemIndex);

		// Mark track to play as playing and unmarking previously playing track
		Q_INVOKABLE void setPlayingTrack(bool isPlaying);

		Q_INVOKABLE QString getTrackToPlayPath();

		Q_INVOKABLE bool forceTrackToPlay(int index);

		// Find next track by order rules and set it to play, default is first track
		Q_INVOKABLE bool setNextTrackToPlay();

	signals:
		int	currentTrackDurationUpdated(int duration);

	private:
		TracksLoader* _tracksLoader;
		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;

		SailPlayerSettings _settings;

		// Current playing data

		int _currentTrackIndex;
		Track* _currentTrackToPlay;
		Track* _currentPlayingTrack;

		void SetTrackToPlayFromCurrentIndex();
		bool CalculateNextTrack(int customIndex);
	};
}

#endif // PLAYLISTMODEL_H

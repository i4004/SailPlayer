#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include "../Playlist/TracksLoader.h"
#include "../Playlist/DirectoryRecursiveMultimediaFilesListFactory.h"
#include "../Playlist/TracksFactory.h"
#include "../SailPlayerSettings.h"
#include "PlaylistModelBase.h"
#include "../Audio/AudioPlayer.h"

using namespace Audio;

namespace Models
{
	class PlaylistModel : public PlaylistModelBase
	{
		Q_OBJECT
		Q_ENUMS(PlayDirection)
		Q_ENUMS(PlayOrder)

	public:
		explicit PlaylistModel(QObject* parent = 0);
		~PlaylistModel();

		enum PlayDirection
		{
			ByIndex = 0,
			Next = 1,
			// Ignoring repeat track order
			NextWithForce = 2,
			Previous = 3
		};

		enum PlayOrder
		{
			Default = 0,
			RepeatPlaylist = 1,
			RepeatTrack = 2,
			Random = 3
		};

		// Playlist controls

		Q_INVOKABLE void addTracks(QString directoryPath);

		Q_INVOKABLE void clearPlaylist();

		// Load playlist from settings
		Q_INVOKABLE void loadPlaylist();

		// Save playlist to settings
		Q_INVOKABLE void savePlaylist();

		Q_INVOKABLE void toggleSelectTrack(int itemIndex);

		// Calculates and sets next track to play
		Q_INVOKABLE bool calculateTrackToPlay(PlayDirection direction = Next, int customIndex = -1);

		Q_INVOKABLE void setPlayOrder(PlayOrder order);

		Q_INVOKABLE bool hasTrackToPlay() { return _currentTrackToPlay != NULL; }

	public slots:
		Q_INVOKABLE void playerStateChanged(AudioPlayer::AudioPlayerState state);

	signals:
		void currentTrackFilePathUpdated(QString filePath);

	private:
		TracksLoader* _tracksLoader;
		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;

		SailPlayerSettings _settings;

		// Current playing data

		PlayOrder _currentPlayOrder;
		int _currentTrackIndex;
		Track* _currentTrackToPlay;
		Track* _currentPlayingTrack;

		void SetTrackToPlayFromCurrentIndex();
		void ResetCurrentTrack();

		// Mark track to play as playing and unmarking previously playing track
		void SetPlayingTrack(bool isPlaying);
	};
}

#endif // PLAYLISTMODEL_H

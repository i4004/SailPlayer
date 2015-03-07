#ifndef PLAYLISTMODEL_HPP
#define PLAYLISTMODEL_HPP

#include "../Playlist/TracksLoader.hpp"
#include "../Playlist/DirectoryRecursiveMultimediaFilesListFactory.hpp"
#include "../Playlist/TracksFactory.hpp"
#include "../Audio/AudioPlayer.hpp"
#include "PlaylistModelBase.hpp"
#include "../SailPlayer.hpp"

using namespace Audio;

namespace Models
{
	class PlaylistModel : public PlaylistModelBase
	{
		Q_OBJECT
		Q_PROPERTY(SailPlayer::PlayOrder playOrder READ GetPlayOrder WRITE SetPlayOrder NOTIFY playOrderChanged)

	public:
		explicit PlaylistModel(QObject* parent = 0);
		~PlaylistModel();

		// Playlist controls

		Q_INVOKABLE void addTracksFromPath(QString directoryPath);

		Q_INVOKABLE void clearPlaylist();

		// Load playlist from settings
		Q_INVOKABLE void loadPlaylist();

		// Save playlist to settings
		Q_INVOKABLE void savePlaylist();

		Q_INVOKABLE void toggleSelectTrack(int itemIndex);

		// Calculates next track to play
		Q_INVOKABLE bool calculateNextTrackToPlay(SailPlayer::PlayDirection direction = SailPlayer::Next, int customIndex = -1);

		// Calculates next track to play and sets current track to play from it
		Q_INVOKABLE bool calculateAndSetTrackToPlay(SailPlayer::PlayDirection direction = SailPlayer::Next, int customIndex = -1);

		Q_INVOKABLE bool hasTrackToPlay() { return _currentTrackToPlay != NULL; }

		Q_INVOKABLE QString requestNextTrack();
		Q_INVOKABLE int getNextStartPosition();
		Q_INVOKABLE int getNextEndPosition();
		Q_INVOKABLE bool setTrackToPlayAndPlayingFromNextTrack();
		Q_INVOKABLE int getCurrentTrackIndex();

		// Return a copy of current playing track, shoube be delete by method user!
		Q_INVOKABLE QObject* getCurrentPlayingTrack();

	public slots:
		Q_INVOKABLE void setPlayerState(AudioPlayer::AudioPlayerState state);

	signals:
		void currentTrackToPlayDataUpdated(QString filePath, int startPosition, int endPosition);
		void playOrderChanged();

	private:
		TracksLoader* _tracksLoader;
		TracksFactory _tracksFactory;
		DirectoryRecursiveMultimediaFilesListFactory _filesFactory;

		// Current playing data

		SailPlayer::PlayOrder _currentPlayOrder;

		Track* _nextTrackToPlay;
		Track* _currentTrackToPlay;
		Track* _currentPlayingTrack;

		bool SetTrackToPlayFromNextTrack();
		void ResetTracksData();

		// Mark track to play as playing and unmarking previously playing track
		void SetPlayingTrack(bool isPlaying);

		void SetPlayOrder(SailPlayer::PlayOrder order) { _currentPlayOrder = order; }
		SailPlayer::PlayOrder GetPlayOrder() { return _currentPlayOrder; }
	};
}

#endif // PLAYLISTMODEL_HPP

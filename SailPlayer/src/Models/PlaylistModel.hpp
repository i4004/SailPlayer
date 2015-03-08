#ifndef PLAYLISTMODEL_HPP
#define PLAYLISTMODEL_HPP

#include "../Audio/AudioPlayerEnums.hpp"
#include "../Playlist/PlaylistEnums.hpp"
#include "PlaylistModelBase.hpp"

using namespace Audio;

namespace Models
{
	class PlaylistModel : public PlaylistModelBase
	{
		Q_OBJECT
		Q_PROPERTY(Playlist::PlaylistEnums::PlayOrder playOrder READ GetPlayOrder WRITE SetPlayOrder NOTIFY PlayOrderChanged)

	public:
		explicit PlaylistModel(QObject* parent = 0);

		void SetPlayOrder(PlaylistEnums::PlayOrder order) { _currentPlayOrder = order; }
		PlaylistEnums::PlayOrder GetPlayOrder() { return _currentPlayOrder; }

		// Playlist controls

		Q_INVOKABLE void clearPlaylist();

//		// Calculates next track to play
		bool CalculateNextTrackToPlay(PlaylistEnums::PlayDirection direction = PlaylistEnums::Next, int customIndex = -1);

		// Calculates next track to play and sets current track to play from it
		bool CalculateAndSetTrackToPlay(PlaylistEnums::PlayDirection direction = PlaylistEnums::Next, int customIndex = -1);

//		Q_INVOKABLE QString requestNextTrack();
//		Q_INVOKABLE bool setTrackToPlayAndPlayingFromNextTrack();

		// Info

		bool HasTrackToPlay() { return _currentTrackToPlay != NULL; }
//		Q_INVOKABLE int getNextStartPosition();
//		Q_INVOKABLE int getNextEndPosition();
//		Q_INVOKABLE int getCurrentTrackIndex();

//		// Return a copy of current playing track, shoube be delete by method user!
//		Q_INVOKABLE QObject* getCurrentPlayingTrack();

	public slots:
		void SetPlayerState(AudioPlayerEnums::AudioPlayerState state);

	signals:
		void CurrentTrackToPlayDataUpdated(QString filePath, int startPosition, int endPosition);
		void PlayOrderChanged();

	private:
		// Current playing data

		PlaylistEnums::PlayOrder _currentPlayOrder;

		Track* _nextTrackToPlay;
		Track* _currentTrackToPlay;
		Track* _currentPlayingTrack;

		bool SetTrackToPlayFromNextTrack();
		void ResetTracksData();

		// Mark track to play as playing and unmarking previously playing track
		void SetPlayingTrack(bool isPlaying);
	};
}

#endif // PLAYLISTMODEL_HPP

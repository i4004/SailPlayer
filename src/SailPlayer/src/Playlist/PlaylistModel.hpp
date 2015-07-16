#ifndef PLAYLISTMODEL_HPP
#define PLAYLISTMODEL_HPP

#include "../Audio/AudioPlayerEnums.hpp"
#include "PlaylistEnums.hpp"
#include "PlaylistModelBase.hpp"

using namespace Audio;

namespace Playlist
{
	class PlaylistModel : public PlaylistModelBase
	{
		Q_OBJECT
		Q_PROPERTY(Playlist::PlaylistEnums::PlayOrder playOrder READ GetPlayOrder NOTIFY PlayOrderChanged)

	public:
		explicit PlaylistModel(QObject* parent = 0);

		void SetPlayOrder(PlaylistEnums::PlayOrder order) { _currentPlayOrder = order; }
		PlaylistEnums::PlayOrder GetPlayOrder() { return _currentPlayOrder; }

		void Clear();

		// Calculates next track to play
		bool CalculateNextTrackToPlay(PlaylistEnums::PlayDirection direction = PlaylistEnums::Next, int customIndex = -1);

		// Calculates next track to play and sets current track to play from it
		bool CalculateAndSetTrackToPlay(PlaylistEnums::PlayDirection direction = PlaylistEnums::Next, int customIndex = -1);

		QString RequestNextTrack();
		bool SetTrackToPlayAndPlayingFromNextTrack();

		// Info

		bool HasTrackToPlay() { return _currentTrackToPlay != NULL; }
		int GetNextStartPosition();
		int GetNextEndPosition();
		int GetCurrentTrackIndex();
		Track* GetCurrentPlayingTrack();
		bool IstTrackRequested() { return _trackRequested; }

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
		bool _trackRequested;

		bool SetTrackToPlayFromNextTrack();
		void ResetTracksData();

		// Mark track to play as playing and unmarking previously playing track
		void SetPlayingTrack(bool isPlaying);
	};
}

#endif // PLAYLISTMODEL_HPP

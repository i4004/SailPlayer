#ifndef PLAYLISTHELPER_HPP
#define PLAYLISTHELPER_HPP

#include <QList>

#include "../SailPlayer.hpp"
#include "Track.hpp"
\
namespace Playlist
{
	class PlaylistHelper
	{
	public:
		PlaylistHelper();

		static int CalculateNextTrackIndex(SailPlayer::PlayDirection direction, SailPlayer::PlayOrder playOrder, int customIndex, QList<Track*> tracksList, Track* currentTrack);
	};
}

#endif // PLAYLISTHELPER_HPP

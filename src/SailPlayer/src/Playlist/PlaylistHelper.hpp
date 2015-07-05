#ifndef PLAYLISTHELPER_HPP
#define PLAYLISTHELPER_HPP

#include <QList>

#include "PlaylistEnums.hpp"
#include "Track.hpp"

namespace Playlist
{
	class PlaylistHelper
	{
	public:
		static int CalculateNextTrackIndex(PlaylistEnums::PlayDirection direction, PlaylistEnums::PlayOrder playOrder, int customIndex, QList<Track*> tracksList, Track* currentTrack);
	};
}

#endif // PLAYLISTHELPER_HPP

#include "Track.hpp"

namespace Tracks
{
	Track::Track()
		: IdentityObject(-1)
	{
	}

	Track::Track(Track& track)
		: IdentityObject(track),
		  _playlistID(track.GetPlaylistID()),
		  _artistName(track.GetArtistName()),
		  _albumName(track.GetAlbumName()),
		  _albumYear(track.GetAlbumYear()),
		  _number(track.GetNumber()),
		  _name(track.GetName()),
		  _startPosition(track.GetStartPosition()),
		  _endPosition(track.GetEndPosition()),
		  _fileName(track.GetFileName()),
		  _fullFilePath(track.GetFullFilePath())
	{
	}
}

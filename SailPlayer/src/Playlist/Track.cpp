#include "Track.hpp"

namespace Playlist
{
	Track::Track(QString artistName,
				 QString albumName,
				 int albumYear,
				 int number,
				 QString name,
				 int startPosition,
				 int endPosition,
				 QString fileName,
				 QString fullFilePath)
		: _artistName(artistName),
		  _albumName(albumName),
		  _albumYear(albumYear),
		  _number(number),
		  _name(name),
		  _startPosition(startPosition),
		  _endPosition(endPosition),
		  _fileName(fileName),
		  _fullFilePath(fullFilePath)
	{
//		_isTrackToPlay = false;
//		_playing = false;
	}

	Track::Track(Track& track)
	{
//		_isTrackToPlay = false;
//		_playing = false;

		_artistName = track.GetArtistName();
		_albumName = track.GetAlbumName();
		_albumYear = track.GetAlbumYear();
		_number = track.GetNumber();
		_name = track.GetName();
		_startPosition = track.GetStartPosition();
		_endPosition = track.GetEndPosition();
		_fileName = track.GetFileName();
		_fullFilePath = track.GetFullFilePath();
	}
}

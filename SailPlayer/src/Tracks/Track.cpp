#include "Track.hpp"

namespace Tracks
{
	Track::Track(int id,
				 const QString& artistName,
				 const QString& albumName,
				 int albumYear,
				 int number,
				 const QString& name,
				 int startPosition,
				 int endPosition,
				 const QString& fileName,
				 const QString& fullFilePath)
		: IdentityObject(id),
		  _artistName(artistName),
		  _albumName(albumName),
		  _albumYear(albumYear),
		  _number(number),
		  _name(name),
		  _startPosition(startPosition),
		  _endPosition(endPosition),
		  _fileName(fileName),
		  _fullFilePath(fullFilePath)
	{
	}

	Track::Track(Track& track)
		: IdentityObject(track),
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

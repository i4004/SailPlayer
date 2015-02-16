#include "Track.hpp"

namespace Playlist
{
	Track::Track(QString artistName, QString albumName, int albumYear, int number, QString name, int startPosition, int endPosition, QString fileName, QString fullFilePath)
		: _artistName(artistName), _albumName(albumName), _albumYear(albumYear), _number(number), _name(name), _startPosition(startPosition), _endPosition(endPosition),
		  _fileName(fileName), _fullFilePath(fullFilePath)
	{
		_selected = false;
		_isTrackToPlay = false;
		_playing = false;
	}
}

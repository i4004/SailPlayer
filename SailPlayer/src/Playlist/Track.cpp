#include "Track.h"

namespace Playlist
{
	Track::Track(QString artistName, QString albumName, int albumYear, int number, QString name, int duration, QString fileName, QString fullFilePath)
		: _artistName(artistName), _albumName(albumName), _albumYear(albumYear), _number(number), _name(name), _duration(duration),
		  _fileName(fileName), _fullFilePath(fullFilePath)
	{
	}
}

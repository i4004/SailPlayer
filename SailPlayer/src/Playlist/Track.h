#ifndef TRACK_H
#define TRACK_H

#include <QString>

namespace Playlist
{
	class Track
	{
	public:
		Track(QString artistName, QString albumName, int albumYear, int number, QString name, int duration, QString sourceFileName);

		QString GetArtistName(){ return _artistName; }
		QString GetAlbumName(){ return _albumName; }
		int GetAlbumYear(){ return _albumYear; }
		int GetNumber(){ return _number; }
		QString GetName(){ return _name; }
		int GetDuration(){ return _duration; }
		QString GetSourceFileName(){ return _sourceFileName; }

	private:
		QString _artistName;
		QString _albumName;
		int _albumYear;
		int _number;
		QString _name;
		int _duration;
		QString _sourceFileName;
	};
}

#endif // TRACK_H

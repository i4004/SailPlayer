#ifndef TRACK_H
#define TRACK_H

#include <QString>

namespace Playlist
{
	class Track
	{
	public:
		Track(QString artistName, QString albumName, int albumYear, int number, QString name, int duration, QString fileName, QString fullFilePath);

		QString GetArtistName(){ return _artistName; }
		QString GetAlbumName(){ return _albumName; }
		int GetAlbumYear(){ return _albumYear; }
		int GetNumber(){ return _number; }
		QString GetName(){ return _name; }
		int GetDuration(){ return _duration; }
		QString GetFileName(){ return _fileName; }
		QString GetFullFilePath(){ return _fullFilePath; }

	private:
		QString _artistName;
		QString _albumName;
		int _albumYear;
		int _number;
		QString _name;
		int _duration;
		QString _fileName;
		QString _fullFilePath;
	};
}

#endif // TRACK_H

#ifndef TRACK_H
#define TRACK_H

#include <QString>

namespace Playlist
{
	class Track
	{
	public:
		Track(QString artisName, QString albumName, QString albumYear, QString number, QString name, QString duration, QString sourceFileName);

		QString GetArtistName(){ return _artistName; }
		QString GetAlbumName(){ return _albumName; }
		QString GetAlbumYear(){ return _albumYear; }
		QString GetNumber(){ return _number; }
		QString GetName(){ return _name; }
		QString GetDuration(){ return _duration; }
		QString GetSourceFileName(){ return _sourceFileName; }

	private:
		QString _artistName;
		QString _albumName;
		QString _albumYear;
		QString _number;
		QString _name;
		QString _duration;
		QString _sourceFileName;
	};
}

#endif // TRACK_H

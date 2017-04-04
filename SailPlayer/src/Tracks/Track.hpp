#ifndef TRACK_HPP
#define TRACK_HPP

#include <QString>

#include "../Model/IdentityObject.hpp"

using namespace Model;

namespace Tracks
{
	class Track : public IdentityObject
	{
	public:
		Track(int id,
			  const QString& artistName,
			  const QString& albumName,
			  int albumYear,
			  int number,
			  const QString& name,
			  int startPosition /* msec */,
			  int endPosition /* msec */,
			  const QString& fileName,
			  const QString& fullFilePath);

		Track(Track& track);

		QString GetArtistName() { return _artistName; }
		QString GetAlbumName() { return _albumName; }
		int GetAlbumYear() { return _albumYear; }
		int GetNumber() { return _number; }
		QString GetName() { return _name; }
		int GetStartPosition() { return _startPosition; }
		int GetEndPosition() { return _endPosition; }
		QString GetFileName() { return _fileName; }
		QString GetFullFilePath() { return _fullFilePath; }

		// Track duration in msec
		int GetDuration() { return _endPosition - _startPosition; }

	private:
		QString _artistName;
		QString _albumName;
		int _albumYear;
		int _number;
		QString _name;
		int _startPosition;
		int _endPosition;
		QString _fileName;
		QString _fullFilePath;
	};
}

#endif // TRACK_HPP

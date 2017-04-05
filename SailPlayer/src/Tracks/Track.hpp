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
		Track();
		Track(Track& track);

		inline int GetPlaylistID() { return _playlistID; }
		inline void SetPlaylistID(int playlistID) { _playlistID = playlistID; }

		inline QString GetArtistName() { return _artistName; }
		inline void SetArtistName(const QString& artistName) { _artistName = artistName; }

		inline QString GetAlbumName() { return _albumName; }
		inline void SetAlbumName(const QString& albumName) { _albumName = albumName; }

		inline int GetAlbumYear() { return _albumYear; }
		inline void SetAlbumYear(int albumYear) { _albumYear = albumYear; }

		inline int GetNumber() { return _number; }
		inline void SetNumber(int number) { _number = number; }

		inline QString GetName() { return _name; }
		inline void SetName(const QString& name) { _name =  name; }

		inline int GetStartPosition() { return _startPosition; }
		inline void SetStartPosition(int startPosition) { _startPosition =  startPosition; }

		inline int GetEndPosition() { return _endPosition; }
		inline void SetEndPosition(int endPosition) { _endPosition =  endPosition; }

		inline QString GetFileName() { return _fileName; }
		inline void SetFileName(const QString& fileName) { _fileName =  fileName; }

		inline QString GetFullFilePath() { return _fullFilePath; }
		inline void SetFullFilePath(const QString& fullFilePath) { _fullFilePath =  fullFilePath; }

		// Track duration in msec
		inline int GetDuration() { return _endPosition - _startPosition; }

	private:
		int _playlistID;
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

#ifndef TRACK_HPP
#define TRACK_HPP

#include <QString>

namespace Playlist
{
	class Track
	{
	public:
		Track(QString artistName, QString albumName, int albumYear, int number, QString name, int startPosition, int endPosition, QString fileName, QString fullFilePath);

		QString GetArtistName(){ return _artistName; }
		QString GetAlbumName(){ return _albumName; }
		int GetAlbumYear(){ return _albumYear; }
		int GetNumber(){ return _number; }
		QString GetName(){ return _name; }

		int GetStartPosition(){ return _startPosition; }
		int GetEndPosition(){ return _endPosition; }
		int GetDuration(){ return _endPosition - _startPosition; }

		QString GetFileName(){ return _fileName; }
		QString GetFullFilePath(){ return _fullFilePath; }

		void SetEndPosition(int endPosition){ _endPosition = endPosition; }

		bool IsSelected(){ return _selected; }
		void SetSelected(bool selected){ _selected = selected; }

		// Track is selected to play but can be stopped or paused

		bool IsTrackToPlay(){ return _isTrackToPlay; }
		void SetAsTrackToPlay(bool isTrackToPlay){ _isTrackToPlay = isTrackToPlay; }

		// Track is playing

		bool IsPlaying(){ return _playing; }
		void SetPlaying(bool playing){ _playing = playing; }

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

		bool _selected;
		bool _isTrackToPlay;
		bool _playing;
	};
}

#endif // TRACK_HPP

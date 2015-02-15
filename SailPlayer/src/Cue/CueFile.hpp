#ifndef CUEFILE_HPP
#define CUEFILE_HPP

#include <QList>

#include "CueFileType.hpp"
#include "CueTrack.hpp"

namespace Cue
{
	class CueFile
	{
	public:
		CueFile(QString fileName, CueFileType fileType, QList<CueTrack> tracks);

		QString GetFileName() { return _fileName; }
		CueFileType GetFileType() { return _fileType; }
		QList<CueTrack> GetTracks() { return _tracks; }

	private:
		QString _fileName;
		CueFileType _fileType;
		QList<CueTrack> _tracks;
	};
}

#endif // CUEFILE_HPP

#ifndef CUEFILE_HPP
#define CUEFILE_HPP

#include <QString>
#include <QList>

#include "CueFileType.hpp"
#include "CueTrack.hpp"

using namespace Cue::FileType;

namespace Cue
{
	class CueFile
	{
	public:
		CueFile(QString fileName, CueFileType fileType);
		~CueFile();

		void AddTrack(CueTrack* track) { _tracks.append(track); }

		QString GetFileName() { return _fileName; }
		CueFileType GetFileType() { return _fileType; }
		QList<CueTrack*> GetTracks() { return _tracks; }

	private:
		QString _fileName;
		CueFileType _fileType;
		QList<CueTrack*> _tracks;
	};
}

#endif // CUEFILE_HPP

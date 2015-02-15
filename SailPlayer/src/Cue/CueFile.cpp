#include "CueFile.hpp"

namespace Cue
{
	CueFile::CueFile(QString fileName, CueFileType fileType, QList<CueTrack> tracks)
	{
		_fileName = fileName;
		_fileType = fileType;
		_tracks = tracks;
	}
}

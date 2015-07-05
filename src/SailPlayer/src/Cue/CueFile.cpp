#include "CueFile.hpp"

namespace Cue
{
	CueFile::CueFile(QString fileName, CueFileType fileType)
	{
		_fileName = fileName;
		_fileType = fileType;
	}

	CueFile::~CueFile()
	{
		while (!_tracks.isEmpty())
			delete _tracks.takeFirst();
	}
}

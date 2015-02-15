#ifndef CUESHEET_HPP
#define CUESHEET_HPP

#include "CueFile.hpp"

namespace Cue
{
	class CueSheet
	{
	public:
		CueSheet(QList<CueFile> files);

		QList<CueFile> GetFiles() { return _files; }

	private:
		QList<CueFile> _files;
	};
}

#endif // CUESHEET_HPP

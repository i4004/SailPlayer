#ifndef CUESHEET_HPP
#define CUESHEET_HPP

#include "CueFile.hpp"

namespace Cue
{
	class CueSheet
	{
	public:
		CueSheet();
		~CueSheet();

		void AddFile(CueFile* file) { _files.append(file); }

		QList<CueFile*> GetFiles() { return _files; }

	private:
		QList<CueFile*> _files;
	};
}

#endif // CUESHEET_HPP

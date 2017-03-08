#include "CueSheet.hpp"

namespace Cue
{
	CueSheet::CueSheet()
	{
	}

	CueSheet::~CueSheet()
	{
		while (!_files.isEmpty())
			delete _files.takeFirst();
	}
}

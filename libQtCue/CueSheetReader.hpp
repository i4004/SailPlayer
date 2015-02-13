#ifndef CUESHEETREADER_HPP
#define CUESHEETREADER_HPP

#include "CueSheetParser.hpp"

namespace QtCue
{
	class CueSheetReader
	{
	public:
		CueSheetReader();

	private:
		CueSheetParser parser;
	};
}

#endif // CUESHEETREADER_HPP

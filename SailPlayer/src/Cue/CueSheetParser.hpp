#ifndef CUESHEETPARSER_HPP
#define CUESHEETPARSER_HPP

#include <QString>

#include "CueSheet.hpp"

namespace Cue
{
	class CueSheetParser
	{
	public:
		CueSheetParser();

		CueSheet* Parse(QString cueSheetData);
	};
}

#endif // CUESHEETPARSER_HPP

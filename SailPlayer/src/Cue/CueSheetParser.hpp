#ifndef CUESHEETPARSER_HPP
#define CUESHEETPARSER_HPP

#include <QStringList>

#include "CueSheet.hpp"

namespace Cue
{
	class CueSheetParser
	{
	public:
		CueSheetParser();

		CueSheet* Parse(QString cueSheetData);
		CueSheet* Parse(QStringList cueSheetData);
	};
}

#endif // CUESHEETPARSER_HPP

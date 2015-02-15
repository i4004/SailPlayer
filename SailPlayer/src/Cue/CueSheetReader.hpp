#ifndef CUESHEETREADER_HPP
#define CUESHEETREADER_HPP

#include <QStringList>

#include "CueSheetParser.hpp"

namespace Cue
{
	class CueSheetReader
	{
	public:
		CueSheetReader();

		CueSheet* Read(QString cueFileName);

	private:
		CueSheetParser parser;

		QStringList ReadFileData(QString cueFileName);
	};
}

#endif // CUESHEETREADER_HPP

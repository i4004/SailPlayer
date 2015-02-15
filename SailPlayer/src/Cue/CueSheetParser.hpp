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

	private:
		CueFile* ParseFileHeader(QString data);
		CueTrack* ParseTrackHeader(QString data);
		CueFileType ParseFileType(QString data);
		CueTrackDataType ParseTrackDataType(QString data);
	};
}

#endif // CUESHEETPARSER_HPP

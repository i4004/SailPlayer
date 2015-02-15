#include <QFile>

#include "CueSheetReader.hpp"

namespace Cue
{
	CueSheetReader::CueSheetReader()
	{
	}

	CueSheet* CueSheetReader::Read(QString cueFileName)
	{
//		QStringList items = ReadFileData(cueFileName);

//		if(items.count() == 0)
//			return CueSheet();

//		CueSheet* cue = new CueSheet();

//		foreach(QString item, items)
//		{
//		}

//		return cue;
		return NULL;
	}

	QStringList CueSheetReader::ReadFileData(QString cueFileName)
	{
		QFile file(cueFileName);
		QStringList items;

		while(!file.atEnd())
			items.append(file.readLine());

		return items;
	}
}

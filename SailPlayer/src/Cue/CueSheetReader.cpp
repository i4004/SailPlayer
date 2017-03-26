#include <QFile>
#include <QTextStream>

#include "CueSheetReader.hpp"

namespace Cue
{
	CueSheetReader::CueSheetReader()
	{
	}

	CueSheet* CueSheetReader::Read(QString cueFileName)
	{
		if(!QFile::exists(cueFileName))
			return nullptr;

		QStringList items = ReadFileData(cueFileName);

		if(items.count() == 0)
			return nullptr;

		return parser.Parse(items);
	}

	QStringList CueSheetReader::ReadFileData(QString cueFileName)
	{
		QStringList items;
		QFile inputFile(cueFileName);

		if(inputFile.open(QIODevice::ReadOnly))
		{
			QTextStream stream(&inputFile);

			while(!stream.atEnd())
				items.append(stream.readLine());

			inputFile.close();
		}

		return items;
	}
}

#include "CueSheetParser.hpp"

namespace Cue
{
	CueSheetParser::CueSheetParser()
	{
	}

	CueSheet* CueSheetParser::Parse(QString cueSheetData)
	{
		Q_UNUSED(cueSheetData)

		return NULL;
	}

	CueSheet* CueSheetParser::Parse(QStringList cueSheetData)
	{
		CueSheet* cueSheet = new CueSheet();
		CueFile* currentFile = NULL;
		CueTrack* currentTrack = NULL;

		foreach(QString rawItem, cueSheetData)
		{
			QString item = rawItem.trimmed();

			if(item.startsWith("FILE"))
			{
				if(currentFile != NULL)
					cueSheet->AddFile(currentFile);

				currentFile = ParseFileHeader(item);
			}
			else if(item.startsWith("TRACK"))
			{
				if(currentTrack != NULL)
					currentFile->AddTrack(currentTrack);

				currentTrack = ParseTrackHeader(item);
			}
		}

		if(currentFile != NULL)
		{
			if(currentTrack != NULL)
				currentFile->AddTrack(currentTrack);

			cueSheet->AddFile(currentFile);
		}

		return cueSheet;
	}

	CueFile* CueSheetParser::ParseFileHeader(QString data)
	{
		QStringList items = data.split(" ", QString::SkipEmptyParts);

		QString fileName;
		CueFileType fileType = Cue::FileType::Undefined;

		if(items.count() >= 3)
		{
			fileName = items[1];
			fileType = ParseFileType(items[2]);
		}

		return new CueFile(fileName, fileType);
	}

	CueTrack* CueSheetParser::ParseTrackHeader(QString data)
	{
		QStringList items = data.split(" ", QString::SkipEmptyParts);

		int number;
		CueTrackDataType dataType = Cue::TrackDataType::Undefined;

		if(items.count() >= 3)
		{
			number =  items[1].toInt();
			dataType = ParseTrackDataType(items[2]);
		}

		return new CueTrack(number, dataType);
	}

	CueFileType CueSheetParser::ParseFileType(QString data)
	{
		if(data == "BINARY")
			return Binary;

		if(data == "MOTOROLA")
			return Motorola;

		if(data == "AIFF")
			return Aiff;

		if(data == "WAVE")
			return Wave;

		if(data == "MP3")
			return Mp3;

		return Cue::FileType::Undefined;
	}

	CueTrackDataType CueSheetParser::ParseTrackDataType(QString data)
	{
		if(data == "AUDIO")
			return Audio;

		if(data == "CDG")
			return Cdg;

		if(data == "MODE1/2048")
			return Mode12048;

		if(data == "MODE1/2352")
			return Mode12352;

		if(data == "MODE2/2336")
			return Mode22336;

		if(data == "MODE2/2352")
			return Mode22352;

		if(data == "CDI/2336")
			return Cdi2336;

		if(data == "CDI/2352")
			return Cdi2352;

		return Cue::TrackDataType::Undefined;
	}
}

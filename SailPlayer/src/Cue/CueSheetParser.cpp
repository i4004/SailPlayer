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
		QString fileName = data.mid(5, data.lastIndexOf(" ") - 5).replace("\"", "");
		CueFileType fileType = ParseFileType(data.mid(data.lastIndexOf(" ") + 1));

		return new CueFile(fileName, fileType);
	}

	CueTrack* CueSheetParser::ParseTrackHeader(QString data)
	{
		QStringList items = data.split(" ", QString::SkipEmptyParts);

		int number =  items[1].toInt();
		CueTrackDataType dataType = ParseTrackDataType(items[2]);

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
			return Mode1_2048;

		if(data == "MODE1/2352")
			return Mode1_2352;

		if(data == "MODE2/2336")
			return Mode2_2336;

		if(data == "MODE2/2352")
			return Mode2_2352;

		if(data == "CDI/2336")
			return Cdi_2336;

		if(data == "CDI/2352")
			return Cdi_2352;

		return Cue::TrackDataType::Undefined;
	}
}

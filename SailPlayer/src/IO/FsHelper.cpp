#include <QFileInfo>

#include "FsHelper.hpp"

namespace IO
{
	FileType FsHelper::GetFileType(QString fileNameSuffix)
	{
		QString suffix = fileNameSuffix.toLower();

		if(suffix == "aac")
			return Aac;

		if(suffix == "aiff")
			return Aiff;

		if(suffix == "ape")
			return Ape;

		if(suffix == "cue")
			return Cue;

		if(suffix == "flac")
			return Flac;

		if(suffix == "mp3")
			return Mp3;

		if(suffix == "mp4")
			return Mp4;

		if(suffix == "m4a")
			return M4a;

		if(suffix == "ogg")
			return Ogg;

		if(suffix == "wav")
			return Wav;

		if(suffix == "wma")
			return Wma;

		if(suffix == "wv")
			return Wv;

		return Undefined;
	}

	bool FsHelper::exists(const QString& filePath) const
	{
		return QFileInfo(filePath).exists();
	}
}

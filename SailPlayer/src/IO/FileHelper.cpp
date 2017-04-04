#include "FileHelper.hpp"

namespace IO
{
	FileType FileHelper::GetFileType(const QString& fileNameSuffix)
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

	QString FileHelper::GetFsRecordIconName(const FsRecordInfo& item)
	{
		if (item.IsDirectory()) return "folder";

		return GetFileIconName(item.GetFileType());
	}

	QString FileHelper::GetFileIconName(const FileType& fileType)
	{
		switch (fileType)
		{
			case Aac:
			case Aiff:
			case Ape:
			case Cue:
			case Flac:
			case Mp3:
			case Mp4:
			case M4a:
			case Ogg:
			case Wav:
			case Wma:
			case Wv:
				return "file-audio";

			case Undefined:
			case Unknown:
				break;
		}

		return "file";
	}

	bool FileHelper::Exists(const QString& filePath)
	{
		return QFileInfo(filePath).exists();
	}
}

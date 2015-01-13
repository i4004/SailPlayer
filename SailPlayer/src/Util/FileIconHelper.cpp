#include "FileIconHelper.h"

namespace Util
{
	QString FileIconHelper::GetFileIconName(const FileInfo& info)
	{
		if (info.IsDirectory()) return "folder";

		return GetFileIconName(info.GetFileType());
	}

	QString FileIconHelper::GetFileIconName(FileType fileType)
	{
		switch (fileType)
		{
			case Flac:
			case Ogg:
			case Mp3:
			case Wav:
			case Ape:
			case Mp4:
			case Wv:
			case Cue:
				return "file-audio";

			case Undefined:
			case Unknown:
				break;
		}

		return "file";
	}
}

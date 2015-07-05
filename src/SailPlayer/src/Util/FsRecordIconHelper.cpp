#include "FsRecordIconHelper.hpp"

namespace Util
{
	QString FsRecordIconHelper::GetFsRecordIconName(const FsRecordInfo& info)
	{
		if (info.IsDirectory()) return "folder";

		return GetFileIconName(info.GetFileType());
	}

	QString FsRecordIconHelper::GetFileIconName(FileType fileType)
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
}

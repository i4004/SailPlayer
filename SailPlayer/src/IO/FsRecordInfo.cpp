#include "FileHelper.hpp"
#include "FsRecordInfo.hpp"

namespace IO
{
	FsRecordInfo::FsRecordInfo(const QFileInfo& fileInfo) : _fileInfo(fileInfo)
	{
		_fileType = FileHelper::GetFileType(fileInfo.suffix());
	}
}

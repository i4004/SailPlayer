#include "FsHelper.h"
#include "FsRecordInfo.h"

namespace IO
{
	FsRecordInfo::FsRecordInfo(const QFileInfo& fileInfo) : _fileInfo(fileInfo)
	{
		_fileType = FsHelper::GetFileType(fileInfo.suffix());
	}

	QString FsRecordInfo::GetDirPath() const
	{
		QString path = _fileInfo.absolutePath();

		if(!path.endsWith("/"))
			path += "/";

		return path + _fileInfo.fileName();
	}
}

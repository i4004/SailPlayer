#include "FileHelper.hpp"
#include "FsRecordInfo.hpp"

namespace IO
{
	FsRecordInfo::FsRecordInfo(const QFileInfo& fileInfo) : _fileInfo(fileInfo)
	{
		_fileType = FileHelper::GetFileType(fileInfo.suffix());
	}

//	QString FsRecordInfo::GetDirPath() const
//	{
//		QString path = _fileInfo.absolutePath();

//		if(!path.endsWith("/"))
//			path += "/";

//		return path + _fileInfo.fileName();
//	}
}

#ifndef FILEINFO_H
#define FILEINFO_H

#include <QFileInfo>

#include "FileType.h"

namespace IO
{
	class FsRecordInfo
	{
	public:
		explicit FsRecordInfo(const QFileInfo& fileInfo);

		QString GetName() const { return _fileInfo.fileName(); }
		bool IsDirectory() const { return _fileInfo.isDir(); }
		FileType GetFileType() const { return _fileType; }
		QString GetAbsolutePath() const { return _fileInfo.absolutePath(); }
		QString GetFilePath() const { return _fileInfo.filePath(); }
		QString GetDirPath() const;

	private:
		QFileInfo _fileInfo;
		FileType _fileType;
	};
}

#endif // FILEINFO_H

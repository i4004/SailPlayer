#ifndef FILEINFO_H
#define FILEINFO_H

#include <QFileInfo>
#include "FileType.h"

namespace Entities
{
	class FileInfo
	{
	public:
		explicit FileInfo(const QFileInfo& fileInfo);

		QString GetFileName() const { return _fileInfo.fileName(); }
		bool IsDirectory() const { return _fileInfo.isDir(); }
		FileType GetFileType() const { return _fileType; }
		QString GetAbsolutePath() const { return _fileInfo.absolutePath(); }

	private:
		QFileInfo _fileInfo;
		FileType _fileType;
	};
}

#endif // FILEINFO_H

#ifndef FILEINFO_HPP
#define FILEINFO_HPP

#include <QFileInfo>

#include "FileType.hpp"

namespace IO
{
	class FsRecordInfo
	{
	public:
		explicit FsRecordInfo(const QFileInfo& fileInfo);

		inline QString GetName() const { return _fileInfo.fileName(); }
		inline bool IsDirectory() const { return _fileInfo.isDir(); }
		inline QString GetFilePath() const { return _fileInfo.filePath(); }
		FileType GetFileType() const { return _fileType; }
//		QString GetAbsolutePath() const { return _fileInfo.absolutePath(); }
//		QString GetDirPath() const;

	private:
		QFileInfo _fileInfo;
		FileType _fileType;
	};
}

#endif // FILEINFO_HPP

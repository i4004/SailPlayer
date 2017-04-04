#ifndef FILEHELPER_HPP
#define FILEHELPER_HPP

#include "FileType.hpp"
#include "FsRecordInfo.hpp"

namespace IO
{
	class FileHelper
	{
	public:
		static FileType GetFileType(const QString& fileName);
		static QString GetFsRecordIconName(const FsRecordInfo& item);
		static QString GetFileIconName(const FileType& fileType);
		static bool Exists(const QString& filePath);
	};
}

#endif // FILEHELPER_HPP

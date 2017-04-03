#ifndef FILEHELPER_HPP
#define FILEHELPER_HPP

#include "FileType.hpp"
#include "FsRecordInfo.hpp"

namespace IO
{
	class FileHelper
	{
	public:
		static FileType GetFileType(QString fileName);
		static QString GetFsRecordIconName(const FsRecordInfo& item);
		static QString GetFileIconName(FileType fileType);
	};
}

#endif // FILEHELPER_HPP

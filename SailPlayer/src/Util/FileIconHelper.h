#ifndef FILEICONHELPER_H
#define FILEICONHELPER_H

#include "../Entities/FileType.h"
#include "../Entities/FileInfo.h"

using namespace Entities;

namespace Util
{
	class FileIconHelper
	{
	public:
		static QString GetFileIconName(const FileInfo& fileName);
		static QString GetFileIconName(FileType fileType);
	};
}

#endif // FILEICONHELPER_H

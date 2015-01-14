#ifndef FILEICONHELPER_H
#define FILEICONHELPER_H

#include "../IO/FileType.h"
#include "../IO/FsRecordInfo.h"

using namespace IO;

namespace Util
{
	class FsRecordIconHelper
	{
	public:
		static QString GetFsRecordIconName(const FsRecordInfo& fileName);
		static QString GetFileIconName(FileType fileType);
	};
}

#endif // FILEICONHELPER_H

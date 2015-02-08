#ifndef FILEICONHELPER_HPP
#define FILEICONHELPER_HPP

#include "../IO/FileType.hpp"
#include "../IO/FsRecordInfo.hpp"

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

#endif // FILEICONHELPER_HPP

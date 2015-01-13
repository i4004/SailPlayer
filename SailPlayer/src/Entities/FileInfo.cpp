#include "FileInfo.h"
#include "../Util/FileHelper.h"

using namespace Util;

namespace Entities
{
	FileInfo::FileInfo(const QFileInfo& fileInfo) : _fileInfo(fileInfo)
	{
		_fileType = FileHelper::GetFileType(fileInfo.suffix());
	}
}

#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QString>
#include "../Entities/FileType.h"

using namespace Entities;

namespace Util
{
	class FileHelper
	{
	public:
		static FileType GetFileType(QString fileName);
	};
}

#endif // FILEHELPER_H

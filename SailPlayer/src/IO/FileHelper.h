#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QString>
#include "FileType.h"

namespace IO
{
	class FileHelper
	{
	public:
		static FileType GetFileType(QString fileName);
	};
}

#endif // FILEHELPER_H

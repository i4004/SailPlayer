#ifndef FILEINFO_H
#define FILEINFO_H

#include <QFileInfo>

namespace Entities
{
	class FileInfo
	{
	public:
		explicit FileInfo(const QFileInfo& fileInfo);

		QString Name() const { return _fileInfo.fileName(); }

//	private:
		QFileInfo _fileInfo;
	};
}

#endif // FILEINFO_H

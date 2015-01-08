#ifndef FILEINFO_H
#define FILEINFO_H

#include <QFileInfo>

class FileInfo
{
public:
	QString Name() const { return _fileInfo.fileName(); }

private:
	QFileInfo _fileInfo;

};

#endif // FILEINFO_H

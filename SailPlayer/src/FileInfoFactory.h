#ifndef FILEINFOFACTORY_H
#define FILEINFOFACTORY_H

#include "Entities/FileInfo.h"

using namespace Entities;

class FileInfoFactory
{
public:
	FileInfo* Create(QString fileName);
	QList<FileInfo> CreateList(QString directoryName);
};

#endif // FILEINFOFACTORY_H

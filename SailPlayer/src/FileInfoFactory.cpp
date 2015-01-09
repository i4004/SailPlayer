#include <QDir>
#include "FileInfoFactory.h"

using namespace Entities;

FileInfo* FileInfoFactory::Create(QString fileName)
{
	return new FileInfo(*new QFileInfo(fileName));
}

QList<FileInfo> FileInfoFactory::CreateList(QString directoryName)\
{
	QList<FileInfo> filesList;
	QDir directory(directoryName);
	QStringList filesNamesList = directory.entryList();

	foreach (QString fileName, filesNamesList)
		filesList.append(*Create(directory.absoluteFilePath(fileName)));

	return filesList;
}

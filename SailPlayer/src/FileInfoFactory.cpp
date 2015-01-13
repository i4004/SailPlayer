#include <QDir>
#include "FileInfoFactory.h"

using namespace Entities;

FileInfo* FileInfoFactory::Create(QString fileName)
{
	return new FileInfo(QFileInfo(fileName));
}

QList<FileInfo*> FileInfoFactory::CreateList(QString directoryName)\
{
	QList<FileInfo*> filesList;
	QDir directory(directoryName);

	directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDot | QDir::System);
	directory.setSorting(QDir::Name | QDir::DirsFirst);

	QStringList filesNamesList = directory.entryList();

	foreach (QString fileName, filesNamesList)
		filesList.append(Create(directory.absoluteFilePath(fileName)));

	return filesList;
}

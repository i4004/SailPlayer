#include <QDir>

#include "FsRecordInfoFactory.hpp"

namespace IO
{
	FsRecordInfo* FsRecordInfoFactory::Create(QString name)
	{
		return new FsRecordInfo(QFileInfo(name));
	}

	QList<FsRecordInfo*> FsRecordInfoFactory::CreateList(QString directoryPath)
	{
		QList<FsRecordInfo*> items;
		QDir directory(directoryPath);

		if(directoryPath == "/")
			directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		else
			directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDot | QDir::System | QDir::Readable);

		directory.setSorting(QDir::Name | QDir::DirsFirst);

		QStringList names = directory.entryList();

		foreach (QString name, names)
			items.append(Create(directory.absoluteFilePath(name)));

		return items;
	}
}

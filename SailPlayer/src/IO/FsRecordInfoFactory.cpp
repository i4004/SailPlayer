#include <QDir>

#include "FsRecordInfoFactory.hpp"

namespace IO
{
	FsRecordInfo* FsRecordInfoFactory::Create(const QFileInfo& fileInfo)
	{
		return new FsRecordInfo(fileInfo);
	}

	FsRecordInfo* FsRecordInfoFactory::Create(const QString& name)
	{
		return Create(QFileInfo(name));
	}

	QList<FsRecordInfo*> FsRecordInfoFactory::CreateList(const QString& directoryPath)
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

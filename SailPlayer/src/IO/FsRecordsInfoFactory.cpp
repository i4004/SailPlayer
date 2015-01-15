#include <QDir>
#include "FsRecordsInfoFactory.h"

namespace IO
{
	FsRecordInfo* FsRecordsInfoFactory::Create(QString name)
	{
		return new FsRecordInfo(QFileInfo(name));
	}

	QList<FsRecordInfo*> FsRecordsInfoFactory::CreateList(QString directoryName)
	{
		QList<FsRecordInfo*> items;
		QDir directory(directoryName);

		if(directoryName == "/")
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

#include <QDir>

#include "DirectoryRecursiveMultimediaFilesListFactory.h"

namespace Playlist
{
	DirectoryRecursiveMultimediaFilesListFactory::DirectoryRecursiveMultimediaFilesListFactory()
	{
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::Build()
	{
		QList<QFileInfo> fileInfo;
		QDir directory(_directoryPath);

		directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		directory.setSorting(QDir::Name | QDir::DirsFirst);

//		QStringList entries = directory.entryList();

//		foreach (QString name, names)
//			items.append(Create(directory.absoluteFilePath(name)));


		// TODO

		return fileInfo;
	}
}

#include <QDir>
#include <QDebug>

#include "../IO/FsHelper.h"
#include "DirectoryRecursiveMultimediaFilesListFactory.h"

namespace Playlist
{
	DirectoryRecursiveMultimediaFilesListFactory::DirectoryRecursiveMultimediaFilesListFactory()
	{
		_supportedFormats.append(Flac);
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::Build()
	{
		QList<QFileInfo> items;
		QDir directory(_directoryPath);

		directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		directory.setSorting(QDir::Name | QDir::DirsFirst);

		foreach (QFileInfo entry, directory.entryInfoList())
		{
			if(_supportedFormats.contains(FsHelper::GetFileType(entry.suffix())))
				items.append(entry);
		}

		return items;
	}
}

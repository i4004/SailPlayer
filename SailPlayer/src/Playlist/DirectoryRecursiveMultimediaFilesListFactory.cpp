#include <QDir>
#include <QDebug>

#include "../IO/FsHelper.hpp"
#include "DirectoryRecursiveMultimediaFilesListFactory.hpp"

namespace Playlist
{
	DirectoryRecursiveMultimediaFilesListFactory::DirectoryRecursiveMultimediaFilesListFactory()
	{
		_supportedFormats.append(Flac);
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::Build()
	{
		QList<QFileInfo> items;

		items.append(GetDirectoryFiles(_directoryPath));

		return items;
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::GetDirectoryFiles(QString directoryPath)
	{
		QList<QFileInfo> items;
		QDir directory(directoryPath);

		directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		directory.setSorting(QDir::Name | QDir::DirsFirst);

		foreach (QFileInfo entry, directory.entryInfoList())
		{
			if(entry.isDir())
				items.append(GetDirectoryFiles(entry.absoluteFilePath()));
			else if(_supportedFormats.contains(FsHelper::GetFileType(entry.suffix())))
				items.append(entry);
		}

		return items;
	}
}

#include "DirectoryRecursiveMultimediaFilesListFactory.h"

namespace Playlist
{
	DirectoryRecursiveMultimediaFilesListFactory::MultimediaFilesListFactory()
	{
	}

	QList<QFileInfo> DirectoryRecursiveMultimediaFilesListFactory::MultimediaFilesListFactory::Build(QString directoryPath)
	{
		Q_UNUSED(directoryPath);

		QList<QFileInfo> fileInfo;

		// TODO

		return fileInfo;
	}
}

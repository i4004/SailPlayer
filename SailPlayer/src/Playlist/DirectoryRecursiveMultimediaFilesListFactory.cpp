#include "MultimediaFilesListFactory.h"

namespace Playlist
{
	MultimediaFilesListFactory::MultimediaFilesListFactory()
	{
	}

	QList<QFileInfo> MultimediaFilesListFactory::MultimediaFilesListFactory::Build(QString directoryPath)
	{
		Q_UNUSED(directoryPath);

		QList<QFileInfo> fileInfo;

		// TODO

		return fileInfo;
	}
}

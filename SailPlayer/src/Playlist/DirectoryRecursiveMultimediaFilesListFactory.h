#ifndef DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H
#define DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H

#include "IMultimediaFilesListFactory.h"

namespace Playlist
{
	class DirectoryRecursiveMultimediaFilesListFactory : public IMultimediaFilesListFactory
	{
	public:
		DirectoryRecursiveMultimediaFilesListFactory();

		virtual QList<QFileInfo> Build(QString directoryPath);
	};
}

#endif // DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H

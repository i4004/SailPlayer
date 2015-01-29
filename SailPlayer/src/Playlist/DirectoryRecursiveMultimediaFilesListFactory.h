#ifndef DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H
#define DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H

#include "IMultimediaFilesListFactory.h"

namespace Playlist
{
	class DirectoryRecursiveMultimediaFilesListFactory : public IMultimediaFilesListFactory
	{
	public:
		DirectoryRecursiveMultimediaFilesListFactory();

		void SetDirectoryPath(QString path) { _directoryPath = path; }
		virtual QList<QFileInfo> Build();

	private:
		QString _directoryPath;
	};
}

#endif // DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H

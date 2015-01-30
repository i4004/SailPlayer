#ifndef DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H
#define DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H

#include "../IO/FileType.h"
#include "IMultimediaFilesListFactory.h"

using namespace IO;

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
		QList<FileType> _supportedFormats;

		QList<QFileInfo> GetDirectoryFiles(QString directoryPath);
	};
}

#endif // DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_H

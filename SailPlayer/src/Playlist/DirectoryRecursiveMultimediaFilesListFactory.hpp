#ifndef DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_HPP
#define DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_HPP

#include "../IO/FileType.hpp"
#include "IMultimediaFilesListFactory.hpp"

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

#endif // DIRECTORYRECURSIVEMULTIMEDIAFILESLISTFACTORY_HPP

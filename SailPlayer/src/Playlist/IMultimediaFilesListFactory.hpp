#ifndef IMULTIMEDIAFILESLISTFACTORY_HPP
#define IMULTIMEDIAFILESLISTFACTORY_HPP

#include <QList>
#include <QFileInfo>

namespace Playlist
{
	class IMultimediaFilesListFactory
	{
	public:
		virtual ~IMultimediaFilesListFactory(){}

		virtual QList<QFileInfo> Build() = 0;
	};
}

#endif // IMULTIMEDIAFILESLISTFACTORY_HPP

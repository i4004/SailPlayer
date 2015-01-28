#include <QFile>

#include "TracksListFactory.h"
//#include "DirectoryRecursiveMultimediaFilesListFactory.h"

namespace Playlist
{
	TracksListFactory::TracksListFactory()
	{
//		_filesListFactory = new DirectoryRecursiveMultimediaFilesListFactory();
	}

	TracksListFactory::~TracksListFactory()
	{
//		delete _filesListFactory;
	}

	QList<Track> TracksListFactory::Build(QList<QFileInfo> filesInfo)
	{
		Q_UNUSED(filesInfo);

		QList<Track> tracksList;

		return tracksList;
	}
}

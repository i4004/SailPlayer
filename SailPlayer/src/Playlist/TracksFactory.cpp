#include "TracksFactory.h"

namespace Playlist
{
	TracksFactory::TracksFactory()
	{
	}

	QList<Track*> TracksFactory::Build(QList<QFileInfo> filesInfoList)
	{
		QList<Track*> items;

		foreach (QFileInfo fileInfo, filesInfoList)
			items.append(Build(fileInfo));

		return items;
	}

//	QList<Track> TracksLoader::Build(QString fileName)
//	{
//		QList<Track> tracksList;
//		return tracksList;
//	}

	QList<Track*> TracksFactory::Build(QFileInfo fileInfo)
	{
		QList<Track*> items;

		items.append(new Track("2", "trackName", "12:04" , NULL));

		return items;
	}
}

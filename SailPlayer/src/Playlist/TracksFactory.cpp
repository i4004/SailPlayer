#include "TracksFactory.h"

namespace Playlist
{
	TracksFactory::TracksFactory()
	{
	}

	Track* CreateTrack(QString trackName)
	{
		Track* track = new Track("2", trackName, "12:04" , NULL);

		return track;
	}

	QList<Track> TracksFactory::Build(QList<QFileInfo> filesInfoList)
	{
		QList<Track> tracksList;

//		foreach (QString name, filesInfoList)
//			items.append(Create(directory.absoluteFilePath(name)));

		return tracksList;
	}

//	QList<Track> TracksLoader::Build(QString fileName)
//	{
//		QList<Track> tracksList;
//		return tracksList;
//	}

//	QList<Track> TracksLoader::Build(QFileInfo fileInfo)
//	{
//		QList<Track> tracksList;
//		return tracksList;
//	}
}

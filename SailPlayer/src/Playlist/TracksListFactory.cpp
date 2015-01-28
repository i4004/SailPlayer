#include <QFile>
#include <QDir>

#include "TracksListFactory.h"

namespace Playlist
{
	TracksListFactory::TracksListFactory()
	{
	}

	QList<Track> TracksListFactory::Build(QString directoryPath)
	{
		QList<Track> tracks;
		QDir directory(directoryPath);

		directory.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot | QDir::System | QDir::Readable);
		directory.setSorting(QDir::Name | QDir::DirsFirst);

//		QStringList entries = directory.entryList();

//		foreach (QString name, names)
//			items.append(Create(directory.absoluteFilePath(name)));
	}
}

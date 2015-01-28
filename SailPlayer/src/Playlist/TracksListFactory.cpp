#include <QFile>

#include "TracksListFactory.h"

namespace Playlist
{
	TracksListFactory::TracksListFactory()
	{
	}

	QList<Track> TracksListFactory::Build(QString folderName)
	{
		Q_UNUSED(folderName);
	}
}

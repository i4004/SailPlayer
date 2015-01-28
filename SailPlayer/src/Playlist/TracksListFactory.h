#ifndef TRACKSLISTFACTORY_H
#define TRACKSLISTFACTORY_H

#include <QList>

#include "Track.h"

namespace Playlist
{
	class TracksListFactory
	{
	public:
		TracksListFactory();

		QList<Track> Build(QString folderName);
	};
}

#endif // TRACKSLISTFACTORY_H

#ifndef TRACKSLISTFACTORY_H
#define TRACKSLISTFACTORY_H

#include <QList>

#include "TracksFactory.h"

namespace Playlist
{
	class TracksListFactory
	{
	public:
		TracksListFactory();

		QList<Track> Build(QString directoryPath);

	private:
		TracksFactory _tracksFactory;

		QList<Track> BuildCueSheetTracks();
	};
}

#endif // TRACKSLISTFACTORY_H

#ifndef PLAYLISTFACTORY_H
#define PLAYLISTFACTORY_H

#include <QFileInfo>

#include "ITracksFactory.h"
#include "Track.h"

namespace Playlist
{
	class TracksFactory : public ITracksFactory
	{
	public:
		TracksFactory();

		virtual QList<Track> Build(QList<QFileInfo> filesInfoList);

	private:
//		QList<Track> Build(QString fileName);
//		QList<Track> Build(QFileInfo fileInfo);
	};
}

#endif // PLAYLISTFACTORY_H

#ifndef ITRACKSFACTORY_H
#define ITRACKSFACTORY_H

#include <QFileInfo>

#include "Track.h"

namespace Playlist
{
	class ITracksFactory
	{
	public:
		virtual ~ITracksFactory(){}

		virtual QList<Track*> Build(QList<QFileInfo> filesInfoList) = 0;
	};
}

#endif // ITRACKSFACTORY_H

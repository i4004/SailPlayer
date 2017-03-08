#ifndef ITRACKSFACTORY_HPP
#define ITRACKSFACTORY_HPP

#include <QFileInfo>

#include "Track.hpp"

namespace Tracks
{
	class ITracksFactory
	{
	public:
		virtual ~ITracksFactory(){}

		virtual QList<Track*> Build(QList<QFileInfo> filesInfoList) = 0;
	};
}

#endif // ITRACKSFACTORY_HPP

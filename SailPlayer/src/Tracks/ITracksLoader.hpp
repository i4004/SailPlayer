#ifndef ITRACKSLOADER_HPP
#define ITRACKSLOADER_HPP

#include <QObject>
#include <QList>

#include "Track.hpp"

namespace Tracks
{
	class ITracksLoader : public QObject
	{
		Q_OBJECT

	public:
		ITracksLoader();
		virtual QList<Track*> Build() = 0;
	};
}

#endif // ITRACKSLOADER_HPP

#ifndef ITRACKSLOADER_H
#define ITRACKSLOADER_H

#include "Track.h"

namespace Playlist
{
	class ITracksLoader
	{
	public:
		virtual ~ITracksLoader(){}

		virtual QList<Track*> Build() = 0;
	};
}

#endif // ITRACKSLOADER_H

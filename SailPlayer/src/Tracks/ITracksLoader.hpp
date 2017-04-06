#ifndef ITRACKSLOADER_HPP
#define ITRACKSLOADER_HPP

#include "Track.hpp"

namespace Tracks
{
	class ITracksLoader
	{
	public:
		virtual QList<Track*> Build() = 0;
	};
}

#endif // ITRACKSLOADER_HPP

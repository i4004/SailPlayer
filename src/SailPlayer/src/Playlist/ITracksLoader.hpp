#ifndef ITRACKSLOADER_HPP
#define ITRACKSLOADER_HPP

#include "Track.hpp"

namespace Playlist
{
	class ITracksLoader
	{
	public:
		virtual ~ITracksLoader(){}

		virtual QList<Track*> Build() = 0;
	};
}

#endif // ITRACKSLOADER_HPP

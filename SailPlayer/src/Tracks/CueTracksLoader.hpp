#ifndef CUETRACKSLOADER_HPP
#define CUETRACKSLOADER_HPP

#include "FsTracksLoader.hpp"

namespace Tracks
{
	class CueTracksLoader : public FsTracksLoader
	{
	public:
		CueTracksLoader();
		~CueTracksLoader();

		QList<Track*> Build();
	};
}

#endif // CUETRACKSLOADER_HPP

#include "CueTracksLoader.hpp"
#include "FsTracksLoaderFactory.hpp"

namespace Tracks
{
	FsTracksLoaderFactory::FsTracksLoaderFactory()
	{
	}

	QObject* FsTracksLoaderFactory::create()
	{
		return new CueTracksLoader();
	}
}

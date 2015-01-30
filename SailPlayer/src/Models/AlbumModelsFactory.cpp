#include "AlbumModelsFactory.h"

namespace Models
{
	AlbumModelsFactory::AlbumModelsFactory(ITracksLoader& tracksLoader) : _tracksLoader(tracksLoader)
	{
	}
}

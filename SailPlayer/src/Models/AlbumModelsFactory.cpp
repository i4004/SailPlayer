#include "AlbumModelsFactory.h"

namespace Models
{
	AlbumModelsFactory::AlbumModelsFactory(ITracksLoader& tracksLoader) : _tracksLoader(tracksLoader)
	{
	}

	QList<AlbumModel*> AlbumModelsFactory::Build()
	{
		QList<AlbumModel*> items;
		return items;
	}
}

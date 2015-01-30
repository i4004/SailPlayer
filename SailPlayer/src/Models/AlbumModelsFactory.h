#ifndef ALBUMMODELSFACTORY_H
#define ALBUMMODELSFACTORY_H

#include "../Playlist/ITracksLoader.h"
#include "IAlbumModelsFactory.h"

using namespace Playlist;

namespace Models
{
	class AlbumModelsFactory : public IAlbumModelsFactory
	{
	public:
		AlbumModelsFactory(ITracksLoader& tracksLoader);

		virtual QList<AlbumModel*> Build();

	private:
		ITracksLoader& _tracksLoader;
	};
}

#endif // ALBUMMODELSFACTORY_H

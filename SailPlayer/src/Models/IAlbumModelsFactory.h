#ifndef IALBUMMODELSFACTORY_H
#define IALBUMMODELSFACTORY_H

#include "AlbumModel.h"

namespace Models
{
	class IAlbumModelsFactory
	{
	public:
		virtual ~IAlbumModelsFactory(){}

		virtual QList<AlbumModel*> Build() = 0;
	};
}

#endif // IALBUMMODELSFACTORY_H

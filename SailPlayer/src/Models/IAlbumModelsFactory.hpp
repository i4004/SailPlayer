#ifndef IALBUMMODELSFACTORY_HPP
#define IALBUMMODELSFACTORY_HPP

#include "AlbumModel.hpp"

namespace Models
{
	class IAlbumModelsFactory
	{
	public:
		virtual ~IAlbumModelsFactory(){}

		virtual QList<AlbumModel*> Build() = 0;
	};
}

#endif // IALBUMMODELSFACTORY_HPP

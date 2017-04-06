#ifndef FSTRACKSLOADERFACTORY_HPP
#define FSTRACKSLOADERFACTORY_HPP

#include <QObject>

namespace Tracks
{
	class FsTracksLoaderFactory : public QObject
	{
		 Q_OBJECT

	public:
		FsTracksLoaderFactory();

		Q_INVOKABLE QObject* create();
	};
}

#endif // FSTRACKSLOADERFACTORY_HPP

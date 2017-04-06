#include "CueTracksLoader.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Tracks
{
	CueTracksLoader::CueTracksLoader()
	{
		#ifdef QT_DEBUG
		qDebug() << "Construction";
		#endif
	}

	CueTracksLoader::~CueTracksLoader()
	{
		#ifdef QT_DEBUG
		qDebug() << "Destruction";
		#endif
	}

	QList<Track*> CueTracksLoader::Build()
	{
		QList<Track*> items;

		items.append(FsTracksLoader::Build());

		return items;
	}
}

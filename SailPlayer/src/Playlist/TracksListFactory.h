#ifndef TRACKSLISTFACTORY_H
#define TRACKSLISTFACTORY_H

#include <QFileInfo>
#include <QList>

//#include "IMultimediaFilesListFactory.h"
#include "TracksFactory.h"

namespace Playlist
{
	class TracksListFactory : public QObject
	{
		Q_OBJECT

	public:
		TracksListFactory();
		~TracksListFactory();

		QList<Track> Build(QList<QFileInfo> filesInfo);

	private:
		TracksFactory _tracksFactory;
//		IMultimediaFilesListFactory* _filesListFactory;

		QList<Track> BuildCueSheetTracks();
	};
}

#endif // TRACKSLISTFACTORY_H

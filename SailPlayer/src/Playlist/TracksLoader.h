#ifndef TRACKSLOADER_H
#define TRACKSLOADER_H

#include <QString>

#include "ITracksFactory.h"
#include "IMultimediaFilesListFactory.h"
#include "Track.h"

namespace Playlist
{
	class TracksLoader
	{
	public:
		TracksLoader(ITracksFactory& tracksFactory, IMultimediaFilesListFactory& filesListFactory);
		~TracksLoader();

		QList<Track*> Build();

	private:
		ITracksFactory& _tracksFactory;
		IMultimediaFilesListFactory& _filesListFactory;
	};
}

#endif // TRACKSLOADER_H

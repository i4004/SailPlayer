#ifndef TRACKSLOADER_H
#define TRACKSLOADER_H

#include <QString>

#include "ITracksFactory.h"
#include "IMultimediaFilesListFactory.h"
#include "ITracksLoader.h"
#include "Track.h"

namespace Playlist
{
	class TracksLoader : public ITracksLoader
	{
	public:
		TracksLoader(ITracksFactory& tracksFactory, IMultimediaFilesListFactory& filesListFactory);
		~TracksLoader();

		virtual QList<Track*> Build();

	private:
		ITracksFactory& _tracksFactory;
		IMultimediaFilesListFactory& _filesListFactory;
	};
}

#endif // TRACKSLOADER_H

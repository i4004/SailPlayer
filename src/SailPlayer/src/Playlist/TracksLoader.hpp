#ifndef TRACKSLOADER_HPP
#define TRACKSLOADER_HPP

#include <QString>

#include "ITracksFactory.hpp"
#include "IMultimediaFilesListFactory.hpp"
#include "ITracksLoader.hpp"
#include "Track.hpp"

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

#endif // TRACKSLOADER_HPP

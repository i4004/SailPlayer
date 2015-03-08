#include "DirectoryRecursiveMultimediaFilesListFactory.hpp"
#include "TracksLoader.hpp"

namespace Playlist
{
	TracksLoader::TracksLoader(ITracksFactory& tracksFactory, IMultimediaFilesListFactory& filesListFactory)
		: _tracksFactory(tracksFactory), _filesListFactory(filesListFactory)
	{
	}

	TracksLoader::~TracksLoader()
	{
	}

	QList<Track*> TracksLoader::Build()
	{
		return _tracksFactory.Build(_filesListFactory.Build());
	}
}

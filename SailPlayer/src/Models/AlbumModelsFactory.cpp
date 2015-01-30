#include "AlbumModelsFactory.h"

namespace Models
{
	AlbumModelsFactory::AlbumModelsFactory(ITracksLoader& tracksLoader) : _tracksLoader(tracksLoader)
	{
	}

	QList<AlbumModel*> AlbumModelsFactory::Build()
	{
		QList<AlbumModel*> items;
		AlbumModel* album = NULL;
		Track* previousTrack = NULL;

		QList<Track*> tracks = _tracksLoader.Build();

		foreach (Track* track, tracks)
		{
			if(album == NULL)
			{
				album = new AlbumModel();
				album->AddTrack(track);
			}
			else
			{
				if(previousTrack->GetArtistName() != track->GetArtistName() || previousTrack->GetAlbumName() != track->GetAlbumName())
				{
					items.append(album);

					album = new AlbumModel();
					album->AddTrack(track);
				}
				else
					album->AddTrack(track);
			}

			previousTrack = track;
		}

		if(album != NULL && !items.contains(album))
			items.append(album);

		return items;
	}
}

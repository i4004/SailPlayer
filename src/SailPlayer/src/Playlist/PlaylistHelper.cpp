#include "PlaylistHelper.hpp"

namespace Playlist
{
	int PlaylistHelper::CalculateNextTrackIndex(PlaylistEnums::PlayDirection direction, PlaylistEnums::PlayOrder playOrder, int customIndex, QList<Track*> tracksList, Track* currentTrack)
	{
		int trackIndex = -1;

		if(tracksList.count() == 0)
			return -1;

		if(direction == PlaylistEnums::ByIndex)
			return customIndex;
		else
		{
			if(currentTrack == NULL)
				return 0;
			else
			{
				trackIndex = tracksList.indexOf(currentTrack);

				if(direction == PlaylistEnums::Next || direction == PlaylistEnums::NextWithForce)
				{
					switch(playOrder)
					{
						case PlaylistEnums::Default:
						{
							if(trackIndex < tracksList.count() - 1 || direction == PlaylistEnums::NextWithForce)
								trackIndex++;
							else
								return -1;

							break;
						}

						case PlaylistEnums::RepeatPlaylist:
							trackIndex++;
						break;

						case PlaylistEnums::RepeatTrack:
						{
							if(direction == PlaylistEnums::NextWithForce)
								trackIndex++;

							break;
						}

						case PlaylistEnums::Random:
						{
							int randomIndex;

							while((randomIndex = rand() % tracksList.count()) == trackIndex){}

							trackIndex = randomIndex;

							break;
						}
					}
				}
				else if(direction == PlaylistEnums::Previous)
				{
					trackIndex--;

					if(trackIndex == -1)
						trackIndex = tracksList.count() - 1;
				}
			}
		}

		if(trackIndex >= tracksList.count())
			trackIndex = 0;

		return trackIndex;
	}
}

#include "PlaylistHelper.hpp"

namespace Playlist
{
	PlaylistHelper::PlaylistHelper()
	{
	}

	int PlaylistHelper::CalculateNextTrackIndex(SailPlayer::PlayDirection direction, SailPlayer::PlayOrder playOrder, int customIndex, QList<Track*> tracksList, Track* currentTrack)
	{
		int trackIndex = -1;

		if(tracksList.count() == 0)
			return -1;

		if(direction == SailPlayer::ByIndex)
			return customIndex;
		else
		{
			if(currentTrack == NULL)
				return 0;
			else
			{
				trackIndex = tracksList.indexOf(currentTrack);

				if(direction == SailPlayer::Next || direction == SailPlayer::NextWithForce)
				{
					switch(playOrder)
					{
						case SailPlayer::Default:
						{
							if(trackIndex < tracksList.count() - 1 || direction == SailPlayer::NextWithForce)
								trackIndex++;
							else
								return -1;

							break;
						}

						case SailPlayer::RepeatPlaylist:
							trackIndex++;
						break;

						case SailPlayer::RepeatTrack:
						{
							if(direction == SailPlayer::NextWithForce)
								trackIndex++;

							break;
						}

						case SailPlayer::Random:
						{
							int randomIndex;

							while((randomIndex = rand() % tracksList.count()) == trackIndex){}

							trackIndex = randomIndex;

							break;
						}
					}
				}
				else if(direction == SailPlayer::Previous)
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

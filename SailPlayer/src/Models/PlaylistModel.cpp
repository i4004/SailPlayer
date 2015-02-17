#include "PlaylistModel.hpp"

namespace Models
{
	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_currentPlayOrder = RepeatPlaylist;
		_currentTrackToPlay = NULL;
		_currentPlayingTrack = NULL;

		_tracksLoader = new TracksLoader(_tracksFactory, _filesFactory);
	}

	PlaylistModel::~PlaylistModel()
	{		
		delete _tracksLoader;
	}

	void PlaylistModel::addTracks(QString directoryPath)
	{
		_filesFactory.SetDirectoryPath(directoryPath);
		AddTracks(_tracksLoader->Build());
	}

	void PlaylistModel::clearPlaylist()
	{
		beginResetModel();

		ResetCurrentTrack();
		Cleanup();

		endResetModel();
	}

	void PlaylistModel::loadPlaylist()
	{
		AddTracks(_settings.GetPlaylist());
	}

	void PlaylistModel::savePlaylist()
	{
		_settings.SetPlaylist(_tracksList);
	}

	void PlaylistModel::toggleSelectTrack(int itemIndex)
	{
		Track* track = _tracksList.at(itemIndex);

		track->SetSelected(!track->IsSelected());

		emit dataChanged(index(itemIndex, 0), index(itemIndex, 0), QVector<int>(1, IsSelectedRole));
	}

	bool PlaylistModel::calculateAndSetTrackToPlay(PlayDirection direction, int customIndex)
	{
		bool result = calculateNextTrackToPlay(direction, customIndex);

		if(result == false)
			return false;

		setTrackToPlayFromNextTrack();

		return true;
	}

	bool PlaylistModel::calculateNextTrackToPlay(PlayDirection direction, int customIndex)
	{
		int index = CalculateNextTrackIndex(direction, customIndex);

		if(index == -1)
			return false;

		_nextTrackToPlay = _tracksList.at(index);

		return true;
	}

	int PlaylistModel::CalculateNextTrackIndex(PlayDirection direction, int customIndex)
	{
		int trackIndex = -1;

		if(_tracksList.count() == 0)
			return -1;

		if(direction == ByIndex)
			return customIndex;
		else
		{
			if(_currentTrackToPlay == NULL)
				return 0;
			else
			{
				trackIndex = _tracksList.indexOf(_currentTrackToPlay);

				if(direction == Next || direction == NextWithForce)
				{
					switch(_currentPlayOrder)
					{
						case Default:
						{
							if(trackIndex < _tracksList.count() - 1 || direction == NextWithForce)
								trackIndex++;
							else
								return -1;

							break;
						}

						case RepeatPlaylist:
							trackIndex++;
						break;

						case RepeatTrack:
						{
							if(direction == NextWithForce)
								trackIndex++;

							break;
						}

						case Random:
						{
							int randomIndex;

							while((randomIndex = rand() % _tracksList.count()) == trackIndex){}

							trackIndex = randomIndex;

							break;
						}
					}
				}
				else if(direction == Previous)
				{
					trackIndex--;

					if(trackIndex == -1)
						trackIndex = _tracksList.count() - 1;
				}
			}
		}

		if(trackIndex >= _tracksList.count())
			trackIndex = 0;

		return trackIndex;
	}

	void PlaylistModel::playerStateChanged(AudioPlayer::AudioPlayerState state)
	{
		if(state == AudioPlayer::Ready || state == AudioPlayer::Paused)
			SetPlayingTrack(false);
		else
			SetPlayingTrack(true);
	}

	void PlaylistModel::setTrackToPlayFromNextTrack()
	{
		if(_nextTrackToPlay == NULL)
			return;

		if(_currentTrackToPlay != NULL)
			_currentTrackToPlay->SetAsTrackToPlay(false);

		_currentTrackToPlay = _nextTrackToPlay;

		_currentTrackToPlay->SetAsTrackToPlay(true);

		emit dataChanged(index(0, 0), index(_tracksList.count() - 1, 0), QVector<int>(1, IsTrackToPlay));
		emit currentTrackFilePathUpdated(_currentTrackToPlay->GetFullFilePath());
	}

	void PlaylistModel::ResetCurrentTrack()
	{
		_currentTrackToPlay = NULL;
		_currentPlayingTrack = NULL;
	}

	void PlaylistModel::SetPlayingTrack(bool isPlaying)
	{
		if(_currentPlayingTrack != NULL)
			_currentPlayingTrack->SetPlaying(false);

		_currentPlayingTrack = _currentTrackToPlay;

		if(_currentPlayingTrack != NULL)
			_currentPlayingTrack->SetPlaying(isPlaying);

		emit dataChanged(index(0, 0), index(_tracksList.count() - 1, 0), QVector<int>(1, IsPlayingRole));
	}
}

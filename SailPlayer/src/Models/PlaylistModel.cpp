#include "PlaylistModel.hpp"

namespace Models
{
	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_currentTrackIndex= -1;
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

	bool PlaylistModel::calculateTrackToPlay(PlayDirection direction, int customIndex)
	{
		if(_tracksList.count() == 0)
			return false;

		if(direction == ByIndex)
			_currentTrackIndex = customIndex;
		else
		{
			if(_currentTrackIndex == -1)
				_currentTrackIndex = 0;
			else
			{
				if(direction == Next || direction == NextWithForce)
				{
					switch(_currentPlayOrder)
					{
						case Default:
						{
							if(_currentTrackIndex < _tracksList.count() - 1 || direction == NextWithForce)
								_currentTrackIndex++;
							else
								return false;

							break;
						}

						case RepeatPlaylist:
							_currentTrackIndex++;
						break;

						case RepeatTrack:
						{
							if(direction == NextWithForce)
								_currentTrackIndex++;

							break;
						}

						case Random:
						{
							int randomIndex;

							while((randomIndex = rand() % _tracksList.count()) == _currentTrackIndex){}

							_currentTrackIndex = randomIndex;

							break;
						}
					}
				}
				else if(direction == Previous)
				{
					_currentTrackIndex--;

					if(_currentTrackIndex == -1)
						_currentTrackIndex = _tracksList.count() - 1;
				}
			}
		}

		if(_currentTrackIndex >= _tracksList.count())
			_currentTrackIndex = 0;

		SetTrackToPlayFromCurrentIndex();

		return true;
	}

	void PlaylistModel::playerStateChanged(AudioPlayer::AudioPlayerState state)
	{
		if(state == AudioPlayer::Ready || state == AudioPlayer::Paused)
			SetPlayingTrack(false);
		else
			SetPlayingTrack(true);
	}

	void PlaylistModel::SetTrackToPlayFromCurrentIndex()
	{
		if(_currentTrackToPlay != NULL)
			_currentTrackToPlay->SetAsTrackToPlay(false);

		_currentTrackToPlay = _tracksList.at(_currentTrackIndex);

		_currentTrackToPlay->SetAsTrackToPlay(true);

		emit dataChanged(index(0, 0), index(_tracksList.count() - 1, 0), QVector<int>(1, IsTrackToPlay));
		emit currentTrackFilePathUpdated(_currentTrackToPlay->GetFullFilePath());
	}

	void PlaylistModel::ResetCurrentTrack()
	{
		_currentTrackIndex = -1;
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

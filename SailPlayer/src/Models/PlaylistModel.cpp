#include "PlaylistModel.h"

namespace Models
{
	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_currentTrackIndex= -1;
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

	void PlaylistModel::playerStateChanged(AudioPlayer::AudioPlayerState state)
	{
		if(state == AudioPlayer::Ready || state == AudioPlayer::Paused)
			SetPlayingTrack(false);
		else
			SetPlayingTrack(true);
	}


	bool PlaylistModel::forceTrackToPlay(int index)
	{
		if(!CalculateNextTrack(index))
			return false;

		SetTrackToPlayFromCurrentIndex();

		return true;
	}

	bool PlaylistModel::setNextTrackToPlay()
	{
		if(!CalculateNextTrack(-1))
			return false;

		SetTrackToPlayFromCurrentIndex();

		return true;
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

	bool PlaylistModel::CalculateNextTrack(int customIndex)
	{
		if(_tracksList.count() == 0)
			return false;

		if(customIndex > -1)
			_currentTrackIndex = customIndex;
		else
		{
			if(_currentTrackIndex == -1)
				_currentTrackIndex = 0;
			else
				_currentTrackIndex++;
		}

		if(_currentTrackIndex >= _tracksList.count())
			_currentTrackIndex = 0;

		return true;
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

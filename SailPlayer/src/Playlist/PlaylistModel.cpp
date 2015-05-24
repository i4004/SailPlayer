#include "PlaylistHelper.hpp"
#include "PlaylistModel.hpp"

#ifdef _DEBUG
#include <QDebug>
#endif

namespace Playlist
{
	PlaylistModel::PlaylistModel(QObject* parent) : PlaylistModelBase(parent)
	{
		_currentPlayOrder = PlaylistEnums::RepeatPlaylist;
		_nextTrackToPlay = NULL;
		_currentTrackToPlay = NULL;
		_currentPlayingTrack = NULL;
		_trackRequested = false;
	}

	void PlaylistModel::Clear()
	{
		#ifdef _DEBUG
		qDebug() << "Begin";
		#endif

		beginResetModel();

		ResetTracksData();
		DeleteTracks();

		endResetModel();

		#ifdef _DEBUG
		qDebug() << "End";
		#endif
	}

	bool PlaylistModel::CalculateNextTrackToPlay(PlaylistEnums::PlayDirection direction, int customIndex)
	{
		int index = PlaylistHelper::CalculateNextTrackIndex(direction, _currentPlayOrder, customIndex, _tracksList, _currentTrackToPlay);

		if(index == -1)
			return false;

		_nextTrackToPlay = _tracksList.at(index);

		return true;
	}

	bool PlaylistModel::CalculateAndSetTrackToPlay(PlaylistEnums::PlayDirection direction, int customIndex)
	{
		bool result = CalculateNextTrackToPlay(direction, customIndex);

		if(result == false)
			return false;

		SetTrackToPlayFromNextTrack();

		emit CurrentTrackToPlayDataUpdated(_currentTrackToPlay->GetFullFilePath(), _currentTrackToPlay->GetStartPosition(), _currentTrackToPlay->GetEndPosition());

		return true;
	}

	bool PlaylistModel::SetTrackToPlayAndPlayingFromNextTrack()
	{
		_trackRequested = false;

		bool result = SetTrackToPlayFromNextTrack();

		SetPlayingTrack(true);

		return result;
	}

	int PlaylistModel::GetCurrentTrackIndex()
	{
		#ifdef _DEBUG
		qDebug() << "Begin";
		#endif

		if(_currentTrackToPlay == NULL)
			return -1;

		return _tracksList.indexOf(_currentTrackToPlay);

		#ifdef _DEBUG
		qDebug() << "End";
		#endif
	}

	Track* PlaylistModel::GetCurrentPlayingTrack()
	{
		return _currentPlayingTrack;
	}

	bool PlaylistModel::SetTrackToPlayFromNextTrack()
	{
		if(_nextTrackToPlay == NULL)
			return false;

		if(_currentTrackToPlay != NULL)
			_currentTrackToPlay->SetAsTrackToPlay(false);

		_currentTrackToPlay = _nextTrackToPlay;

		_currentTrackToPlay->SetAsTrackToPlay(true);

		emit dataChanged(index(0, 0), index(_tracksList.count() - 1, 0), QVector<int>(1, IsTrackToPlay));

		_nextTrackToPlay = NULL;

		return true;
	}

	void PlaylistModel::SetPlayerState(AudioPlayerEnums::AudioPlayerState state)
	{
		if(state == AudioPlayerEnums::Ready || state == AudioPlayerEnums::Paused)
			SetPlayingTrack(false);
		else
			SetPlayingTrack(true);
	}

	QString PlaylistModel::RequestNextTrack()
	{
		_trackRequested = true;

		bool result = CalculateNextTrackToPlay();

		if(result == true)
			return _nextTrackToPlay->GetFullFilePath();

		return QString();
	}

	int PlaylistModel::GetNextStartPosition()
	{
		if(_nextTrackToPlay != NULL)
			return _nextTrackToPlay->GetStartPosition();
		else
			return -1;
	}

	int PlaylistModel::GetNextEndPosition()
	{
		if(_nextTrackToPlay != NULL)
			return _nextTrackToPlay->GetEndPosition();
		else
			return -1;
	}

	void PlaylistModel::ResetTracksData()
	{
		#ifdef _DEBUG
		qDebug() << "Begin";
		#endif

		_nextTrackToPlay = NULL;
		_currentTrackToPlay = NULL;
		_currentPlayingTrack = NULL;

		#ifdef _DEBUG
		qDebug() << "End";
		#endif
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

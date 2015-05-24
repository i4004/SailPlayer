#include <QObject>

#include "AudioPlayer.hpp"

const int MillisecondsConvertion = 1000000;

namespace Audio
{
	AudioPlayer::AudioPlayer()
	{
		ResetTracksData();

		_currentPositionTimer.setTimerType(Qt::VeryCoarseTimer);
		_currentPositionTimer.setInterval(1000);

		connect(&_currentPositionTimer, SIGNAL(timeout()), this, SLOT(OnCurrentPositionTimerCallback()));
	}

	// Player controls

	void AudioPlayer::Play()
	{
		AudioPlayerEnums::AudioPlayerState state = GetCurrentState();

		if(state == AudioPlayerEnums::Ready)
		{
			_needToSetCurrentPosition = _currentStartPosition != 0;
			_isStreamFromNextTrack = false;
		}

		AudioPlayerBase::Play();

		if(state == AudioPlayerEnums::Paused)
			_currentPositionTimer.start();
	}

	void AudioPlayer::Pause()
	{
		AudioPlayerBase::Pause();

		_currentPositionTimer.stop();
	}

	void AudioPlayer::Stop()
	{
		_currentPositionTimer.stop();

		AudioPlayerBase::Stop();

		emit CurrentPositionUpdated(0);
		emit CurrentDurationUpdated(0);
	}

	void AudioPlayer::SeekInTrack(int trackPosition)
	{
		SeekMs(trackPosition + _currentStartPosition);
	}

	void AudioPlayer::SetTrackToPlay(QString fullFilePath, int startPosition, int endPosition)
	{
		_currentFilePath = fullFilePath;
		_currentStartPosition = startPosition;
		_currentEndPosition = endPosition;
		SetFileToPlay(fullFilePath);
	}

	void AudioPlayer::SetNextTrackToPlay(QString fullFilePath, int startPosition, int endPosition)
	{
		_nextTrackFilePath = fullFilePath;
		_nextTrackStartPosition = startPosition;
		_nextTracktEndPosition = endPosition;
		_nextTrackDataReceived = true;
	}

	void AudioPlayer::OnStreamStart()
	{
		if(_isStreamFromNextTrack)
			SetCurrentPositionsFromNextTrack();

		emit CurrentPositionUpdated(0);
		emit CurrentDurationUpdated(GetCurrentDuration());
		emit StreamStarted();

		if(GetCurrentState() == AudioPlayerEnums::Playing && _needToSetCurrentPosition)
			SeekToCurrentPosition();
		else
			_currentPositionReady = true;

		_currentPositionTimer.start();
	}

	void AudioPlayer::OnAboutToFinish()
	{
		_nextTrackDataReceived = false;
		emit AboutToFinish();
		WaitForNextTrackData();

		if(!_nextTrackFilePath.isNull())
		{
			CalculateNeedToSetCurrentPosition();
			SetFileToPlayFromNextTrack();
		}
	}

	void AudioPlayer::OnEndOfStream()
	{
		emit EndOfStream();
	}

	void AudioPlayer::OnErrorMessage(QString message)
	{
		Stop();
		AudioPlayerBase::OnErrorMessage(message);

		emit PlaybackError(message);
	}

	int AudioPlayer::GetCurrentPositionMs()
	{
		gint64 position = GetCurrentPosition();
		return position == -1 ? -1 : position / MillisecondsConvertion;
	}

	int AudioPlayer::GetCurrentTrackPosition()
	{
		int position = GetCurrentPositionMs();

		return position < 1  ? 0 : position - _currentStartPosition;
	}

	int AudioPlayer::GetCurrentDuration()
	{
		return _currentEndPosition - _currentStartPosition;
	}

	int AudioPlayer::GetCurrentFileDurationMs()
	{
		gint64 duration = GetCurrentFileDuration();
		return duration == -1 ? -1 : duration / MillisecondsConvertion;
	}

	void AudioPlayer::SeekMs(int position)
	{
		_currentPositionReady = false;
		Seek(gint64(position) * MillisecondsConvertion);
		_currentPositionReady = true;
	}

	void AudioPlayer::SeekToCurrentPosition()
	{
		_needToSetCurrentPosition = false;
		SeekMs(_currentStartPosition);
	}

	void AudioPlayer::SetCurrentPositionsFromNextTrack()
	{
		_currentStartPosition = _nextTrackStartPosition;
		_currentEndPosition = _nextTracktEndPosition;
	}

	void AudioPlayer::SetFileToPlayFromNextTrack()
	{
		_isStreamFromNextTrack = true;
		SetFileToPlay(_nextTrackFilePath);
		_currentFilePath = _nextTrackFilePath;
	}

	void AudioPlayer::ResetTracksData()
	{
		_currentFilePath = QString();
		_currentStartPosition = 0;
		_currentEndPosition = 0;
		_needToSetCurrentPosition = false;
		_currentPositionReady = false;
		_nextTrackStartPosition = 0;
		_nextTracktEndPosition = 0;
		_nextTrackDataReceived = false;
		_isStreamFromNextTrack = false;
	}

	void AudioPlayer::CalculateNeedToSetCurrentPosition()
	{
		if((_nextTrackFilePath != _currentFilePath && _nextTrackStartPosition != 0) ||
			(_nextTrackFilePath == _currentFilePath && _currentEndPosition != _nextTrackStartPosition))
			_needToSetCurrentPosition = true;
		else
			_needToSetCurrentPosition = false;
	}

	void AudioPlayer::WaitForNextTrackData()
	{
		while (!_nextTrackDataReceived)
			usleep(1000);
	}

	void AudioPlayer::OnCurrentPositionTimerCallback()
	{
		if(!_currentPositionReady)
			return;

		int currentPosition = GetCurrentPositionMs();
		int currentFileDuration = GetCurrentFileDurationMs();

		if(currentPosition == -1 || currentFileDuration == -1)
			return;

		// If there is an end of track in same file but it is not the end of file
		if(_currentEndPosition - currentPosition < 1000 && currentFileDuration - currentPosition > 2000)
		{
			_nextTrackDataReceived = false;
			emit AboutToFinish();
			WaitForNextTrackData();

			if(!_nextTrackFilePath.isNull())
			{
				bool fileChanging = _nextTrackFilePath != _currentFilePath;

				CalculateNeedToSetCurrentPosition();

				if(fileChanging)
					AudioPlayerBase::Stop();

				SetFileToPlayFromNextTrack();

				if(fileChanging)
					AudioPlayerBase::Play();
				else
					OnStreamStart();
			}
			else
			{
				Stop();
				ResetTracksData();
			}
		}
		else
			emit CurrentPositionUpdated(currentPosition - _currentStartPosition);
	}
}

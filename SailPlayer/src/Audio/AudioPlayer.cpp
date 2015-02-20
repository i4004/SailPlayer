#include <QObject>

#include "AudioPlayer.hpp"

const int MillisecondsConvertion = 1000000;

namespace Audio
{
	AudioPlayer::AudioPlayer()
	{
		_currentPositionsSet = false;
		_currentPositionTimer.setTimerType(Qt::VeryCoarseTimer);
		_currentPositionTimer.setInterval(1000);
		_nextTrackDataReceived = true;

		connect(&_currentPositionTimer, SIGNAL(timeout()), this, SLOT(OnCurrentPositionTimerCallback()));
	}

	// Player controls

	void AudioPlayer::play()
	{\
		_currentPositionsSet = false;

		if(GetCurrentState() == Ready)
			_isStreamFromNextTrack = false;

		AudioPlayerBase::play();
	}

	void AudioPlayer::pause()
	{
		AudioPlayerBase::pause();

		_currentPositionTimer.stop();
	}

	void AudioPlayer::stop()
	{
		_currentPositionTimer.stop();

		AudioPlayerBase::stop();

		emit currentPositionUpdated(0);
		emit currentDurationUpdated(0);
	}

	void AudioPlayer::setTrackToPlay(QString fullFilePath, int startPosition, int endPosition)
	{
		_currentFilePath = fullFilePath;
		_currentStartPosition = startPosition;
		_currentEndPosition = endPosition;
		SetFileToPlay(fullFilePath);
	}

	void AudioPlayer::setNextTrackToPlay(QString fullFilePath, int startPosition, int endPosition)
	{
		_nextTrackFilePath = fullFilePath;
		_nextTrackStartPosition = startPosition;
		_nextTracktEndPosition = endPosition;
		_nextTrackDataReceived = true;
	}

	void AudioPlayer::seek(int milliseconds)
	{
		Seek(gint64(milliseconds + _currentStartPosition) * MillisecondsConvertion);
	}

	void AudioPlayer::OnStreamStart()
	{
		emit currentPositionUpdated(0);
		emit currentDurationUpdated(GetCurrentDuration());
		emit streamStarted();
	}

	void AudioPlayer::OnAsyncDone()
	{
		AudioPlayerState state = GetCurrentState();

		if(state == Playing || state == Paused)
			emit currentDurationUpdated(GetCurrentDuration());

		if(state == Playing && !_currentPositionsSet)
			SeekToCurrentPosition();
		else
			_currentPositionTimer.start();
	}

	void AudioPlayer::OnAboutToFinish()
	{
		_nextTrackDataReceived = false;
		emit aboutToFinish();
		WaitForNextTrackData();

		if(!_nextTrackFilePath.isNull())
			SetCurrentTrackFromNextTrack();
	}

	void AudioPlayer::OnEndOfStream()
	{
		emit endOfStream();
	}

	int AudioPlayer::GetCurrentDuration()
	{
		return _currentEndPosition - _currentStartPosition;
	}

	int AudioPlayer::GetCurrentFileDurationMs()
	{
		return GetCurrentFileDuration() / MillisecondsConvertion;
	}

	void AudioPlayer::SeekMs(int position)
	{
		Seek(gint64(position) * MillisecondsConvertion);
	}

	void AudioPlayer::SeekToCurrentPosition()
	{
		_currentPositionsSet = true;
		SeekMs(_currentStartPosition);
	}

	void AudioPlayer::SetCurrentTrackFromNextTrack()
	{
		_currentStartPosition = _nextTrackStartPosition;
		_currentEndPosition = _nextTracktEndPosition;
		_isStreamFromNextTrack = true;

		if(_nextTrackFilePath != _currentFilePath)
			SetFileToPlay(_nextTrackFilePath);

		_currentFilePath = _nextTrackFilePath;
	}


	void AudioPlayer::WaitForNextTrackData()
	{
		while (!_nextTrackDataReceived)
			usleep(1000);
	}

	void AudioPlayer::OnCurrentPositionTimerCallback()
	{
		int currentPosition = GetCurrentPosition() / MillisecondsConvertion;

		if(_currentEndPosition - currentPosition < 1000 && GetCurrentFileDurationMs() - currentPosition > 2000)
		{
			_nextTrackDataReceived = false;
			emit aboutToFinish();
			WaitForNextTrackData();

			if(!_nextTrackFilePath.isNull())
			{
				if(_nextTrackStartPosition != _currentEndPosition && _nextTrackFilePath != _currentFilePath)
				{
					stop();
					SetCurrentTrackFromNextTrack();
					play();
				}
				else if(_nextTrackStartPosition != _currentEndPosition && _nextTrackFilePath == _currentFilePath)
				{
					SetCurrentTrackFromNextTrack();
					SeekToCurrentPosition();
				}
				else
					SetCurrentTrackFromNextTrack();

				OnStreamStart();
			}
		}

		emit currentPositionUpdated(currentPosition - _currentStartPosition);
	}
}

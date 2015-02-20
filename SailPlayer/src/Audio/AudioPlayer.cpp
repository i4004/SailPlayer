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
		AudioPlayerBase::OnStreamStart();

		emit currentDurationUpdated(GetCurrentDuration());
		emit currentPositionUpdated(0);

//		if(GetCurrentState() == Playing && !_currentPositionsSet)
//			SeekToCurrentPosition();

////		if(_needtToSetOnlyEndPosition)
////		{
////			UpdateEndPosition();
////		}
////		else
////			SeekToCurrentPosition();
	}

	void AudioPlayer::OnAsyncDone()
	{
		AudioPlayerBase::OnAsyncDone();

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
		AudioPlayerBase::OnAboutToFinish();

		_nextTrackDataReceived = false;
		emit aboutToFinish();

		WaitForNextTrackData();

		if(!_nextTrackFilePath.isNull())
		{
			_currentFilePath = _nextTrackFilePath;
			_currentStartPosition = _nextTrackStartPosition;
			_currentEndPosition = _nextTracktEndPosition;

			SetFileToPlay(_currentFilePath);
		}
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
			emit aboutToFinish();

			WaitForNextTrackData();
		}

		emit currentPositionUpdated(currentPosition - _currentStartPosition);
	}
}

#include <QObject>

#include "AudioPlayer.hpp"

const int MillisecondsConvertion = 1000000;

namespace Audio
{
	AudioPlayer::AudioPlayer()
	{
		_currentStartPosition = 0;
		_currentEndPosition = 0;
		_needToSetCurrentPosition = false;
		_currentPositionTimer.setTimerType(Qt::VeryCoarseTimer);
		_currentPositionTimer.setInterval(1000);
		_currentPositionReady = false;
		_nextTrackStartPosition = 0;
		_nextTracktEndPosition = 0;
		_nextTrackDataReceived = false;
		_isStreamFromNextTrack = false;

		connect(&_currentPositionTimer, SIGNAL(timeout()), this, SLOT(OnCurrentPositionTimerCallback()));
	}

	// Player controls

	void AudioPlayer::play()
	{\
		AudioPlayerState state = GetCurrentState();

		if(state == Ready)
		{
			_needToSetCurrentPosition = _currentStartPosition != 0;
			_isStreamFromNextTrack = false;
		}

		AudioPlayerBase::play();

		if(state == Paused)
			_currentPositionTimer.start();
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
		SeekMs(milliseconds + _currentStartPosition);
	}

	void AudioPlayer::OnStreamStart()
	{	
		qDebug() << "start";

		if(_isStreamFromNextTrack)
			SetCurrentPositionsFromNextTrack();

		emit currentDurationUpdated(GetCurrentDuration());
		emit streamStarted();

		if(GetCurrentState() == Playing && _needToSetCurrentPosition)
			SeekToCurrentPosition();
		else
			_currentPositionReady = true;

		_currentPositionTimer.start();
	}

	void AudioPlayer::OnAsyncDone()
	{
////		AudioPlayerState state = GetCurrentState();

////		if(state == Playing || state == Paused)
////			emit currentDurationUpdated(GetCurrentDuration());

//		if(GetCurrentState() == Playing && _currentPositionsSet)
//			_currentPositionTimer.start();
	}

	void AudioPlayer::OnAboutToFinish()
	{
		qDebug() << "aboutToFinish";
		_nextTrackDataReceived = false;
		emit aboutToFinish();
		WaitForNextTrackData();

		if(!_nextTrackFilePath.isNull())
		{
			CalculateNeedToSetCurrentPosition();
			SetFileToPlayFromNextTrack();
		}
	}

	void AudioPlayer::OnEndOfStream()
	{
		emit endOfStream();
	}

	int AudioPlayer::GetCurrentPositionMs()
	{
		 return GetCurrentPosition() / MillisecondsConvertion;
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
		_currentPositionReady = false;
		qDebug() << "seek";
		Seek(gint64(position) * MillisecondsConvertion);
		_currentPositionReady = true;
	}

	void AudioPlayer::SeekToCurrentPosition()
	{
		qDebug() << "set";
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

		// TODO check in CUE file mode
//		if(_nextTrackFilePath != _currentFilePath)
			SetFileToPlay(_nextTrackFilePath);

		_currentFilePath = _nextTrackFilePath;
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

//		if(_currentEndPosition - currentPosition < 1000 && GetCurrentFileDurationMs() - currentPosition > 2000)
//		{
//			_nextTrackDataReceived = false;
//			emit aboutToFinish();
//			WaitForNextTrackData();

//			if(!_nextTrackFilePath.isNull())
//			{
//				if(_nextTrackStartPosition != _currentEndPosition && _nextTrackFilePath != _currentFilePath)
//				{
//					qDebug() << "next1";
//					stop();
//					SetCurrentTrackFromNextTrack();
//					play();
//				}
//				else if(_nextTrackStartPosition != _currentEndPosition && _nextTrackFilePath == _currentFilePath)
//				{
//					qDebug() << "next2";
//					SetCurrentTrackFromNextTrack();
//					SeekToCurrentPosition();
//				}
//				else
//				{
//					qDebug() << "next3";
//					SetCurrentTrackFromNextTrack();
//				}

//				OnStreamStart();
//			}
//		}

		emit currentPositionUpdated(currentPosition - _currentStartPosition);
	}
}

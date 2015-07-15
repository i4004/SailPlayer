#ifndef AUDIOPLAYER_HPP
#define AUDIOPLAYER_HPP

#include <QObject>
#include <QTimer>

#include "AudioPlayerBase.hpp"

namespace Audio
{
	class AudioPlayer : public AudioPlayerBase
	{
		Q_OBJECT

	public:
		AudioPlayer(int equalizerBandsNumber);

		// Player controls

		void Play();
		void Pause();
		void Stop();
		void SeekInTrack(int trackPosition);

		void SetNextTrackToPlay(QString fullFilePath, int startPosition, int endPosition);

		bool HasTrackToPlay() { return !_currentFilePath.isNull() && !_currentFilePath.isEmpty(); }
		bool IsStreamFromNextTrack() { return _isStreamFromNextTrack; }
		int GetCurrentTrackPosition();
		int GetCurrentDuration();

		void OnStreamStart();
		void OnAboutToFinish();
		void OnEndOfStream();
		void OnErrorMessage(QString message);

	public slots:
		void SetTrackToPlay(QString fullFilePath, int startPosition, int endPosition);

	signals:
		void CurrentPositionUpdated(int milliseconds);
		void CurrentDurationUpdated(int duration);
		void AboutToFinish();
		void StreamStarted();
		void EndOfStream();
		void PlaybackError(QString message);

	private:
		// Current state

		QString _currentFilePath;
		int _currentStartPosition;
		int _currentEndPosition;
		bool _needToSetCurrentPosition;
		QTimer _currentPositionTimer;
		bool _currentPositionReady;

		QString _nextTrackFilePath;
		int _nextTrackStartPosition;
		int _nextTracktEndPosition;
		bool _nextTrackDataReceived;
		bool _isStreamFromNextTrack;

		// Internal controls

		int GetCurrentPositionMs();
		int GetCurrentFileDurationMs();

		void SeekMs(int position);
		void SeekToCurrentPosition();
		void SetCurrentPositionsFromNextTrack();
		void SetFileToPlayFromNextTrack();
		void ResetTracksData();
		void CalculateNeedToSetCurrentPosition();

		void WaitForNextTrackData();

	private slots:
		void OnCurrentPositionTimerCallback();
	};
}

#endif // AUDIOPLAYER_HPP

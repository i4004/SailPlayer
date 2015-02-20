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
		AudioPlayer();

		// Player controls

		Q_INVOKABLE virtual void play();
		Q_INVOKABLE virtual void pause();
		Q_INVOKABLE virtual void stop();

		Q_INVOKABLE void setTrackToPlay(QString fullFilePath, int startPosition, int endPosition);
		Q_INVOKABLE void setNextTrackToPlay(QString fullFilePath, int startPosition, int endPosition);
		Q_INVOKABLE void seek(int milliseconds);
		Q_INVOKABLE bool hasTrackToPlay() { return !_currentFilePath.isNull() && !_currentFilePath.isEmpty(); }
//		Q_INVOKABLE bool isStreamFromNextTrack() { return _isStreamFromNextTrack; }

		void OnStreamStart();
		void OnAsyncDone();
		void OnAboutToFinish();

	public slots:
//		void OnEndOfStreamReached();

	signals:
		void currentPositionUpdated(int milliseconds);
		void currentDurationUpdated(int duration);
		void aboutToFinish();
//		void endOfStreamReached();
//		void streamStarted();

	private:
		// Current state

		QString _currentFilePath;
		int _currentStartPosition;
		int _currentEndPosition;
		bool _currentPositionsSet;
		QTimer _currentPositionTimer;

		QString _nextTrackFilePath;
		int _nextTrackStartPosition;
		int _nextTracktEndPosition;
		bool _nextTrackDataReceived;

//		bool _isStreamFromNextTrack;
//		bool _needtToSetOnlyEndPosition;

		// Internal controls

		int GetCurrentDuration();
		int GetCurrentFileDurationMs();
		void SeekMs(int position);
		void SeekToCurrentPosition();
//		void SeekToCurrentPosition();
//		void UpdateEndPosition();

		void WaitForNextTrackData();

	private slots:
		void OnCurrentPositionTimerCallback();
	};
}

#endif // AUDIOPLAYER_HPP

#ifndef AUDIOPLAYER_HPP
#define AUDIOPLAYER_HPP

#include <QObject>
#include <QTimer>
#include <gst/gst.h>
#include "AudioResource.hpp"

namespace Audio
{
	typedef struct
	{
		gfloat freq;
		gfloat width;
		gfloat gain;
	} GstEqualizerBandState;

	class AudioPlayer : public QObject
	{
		Q_OBJECT
		Q_ENUMS(AudioPlayerState)

	public:
		AudioPlayer();
		~AudioPlayer();

		enum AudioPlayerState
		{
			Ready = 0,
			Paused = 1,
			Playing = 2
		};

		// Player controls

		Q_INVOKABLE void play();
		Q_INVOKABLE void pause();
		Q_INVOKABLE void stop();
		Q_INVOKABLE void setTrackToPlay(QString fullFilePath, int startPos, int endPos);
		Q_INVOKABLE void seek(int milliseconds);
		Q_INVOKABLE bool hasTrackToPlay() { return !_fileToPlayFullFilePath.isNull() && !_fileToPlayFullFilePath.isEmpty(); }
		Q_INVOKABLE bool isStreamFromNextTrack() { return _isStreamFromNextTrack; }
		Q_INVOKABLE void setNextTrackToPlay(QString fullFilePath, int startPos, int endPos);

	public slots:
		void OnAudioResourceAquireStateChanged(bool acquired);
		void OnEndOfStreamReached();
		void OnAsyncDone();
		void OnAboutToFinish();
		void OnStreamStart();
		void OnStateChanged();

	signals:
		void currentPositionUpdated(int milliseconds);
		void currentDurationUpdated(int duration);
		void endOfStreamReached();
		void stateChanged(AudioPlayer::AudioPlayerState state);
		void aboutToFinish();
		void streamStarted();

	private slots:
		void OnCurrentPositionTimerCallback();

	private:
		// Audio resoure and modules

		AudioResource* _audioResource;

		GstElement* _pipeline;
		GstElement* _additionalPlugins;
		GstElement* _equalizer;
		GstElement* _sink;

		AudioPlayerState _currentState;
		bool _pausedByResourceBlock;

		// Equalizer

		static int EqualizerBandsNumber;
		GstEqualizerBandState _equalizerData[];

		// Current playing data

		QTimer _currentPositionTimer;
		GstFormat _gstTimeFormat;

		QString _fileToPlayFullFilePath;
		int _currentStartPosition;
		int _currentEndPosition;
		bool _currentPositionsSet;

		bool _nextTrackDataReceived;
		bool _isStreamFromNextTrack;
//		bool _needtToSetOnlyEndPosition;

		// Gstreamer callbacks

		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);
		static void OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData);

		void WaitForNextTrackData();

		// Modules control

		bool Init();
		void SetEqualizerData();
		gint64 GetCurrentPosition();
		int GetCurrentDuration();
		void Seek(gint64 nanoseconds);
//		void SeekToCurrentPosition();
//		void UpdateEndPosition();
	};
}

#endif // AUDIOPLAYER_HPP

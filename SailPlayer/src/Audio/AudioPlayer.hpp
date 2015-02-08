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
		Q_INVOKABLE void setFileToPlay(QString fullFilePath);
		Q_INVOKABLE void seek(int seconds);
		Q_INVOKABLE bool hasFileToPlay() { return !_fileToPlayFullFilePath.isNull() && !_fileToPlayFullFilePath.isEmpty(); }

	public slots:
		void OnAudioResourceAquireStateChanged(bool acquired);
		void OnEndOfStreamReached();
		void OnAsyncDone();

	signals:
		void currentPositionUpdated(int seconds);
		void currentDurationUpdated(int duration);
		void endOfStreamReached();
		void stateChanged(AudioPlayer::AudioPlayerState state);

	private slots:
		void OnCurrentPositionTimerCallback();

	private:
		// Audio resoure and modules

		AudioResource* _audioResource;

		GstElement* _pipeline;
		GstElement* _source;
		GstElement* _decoder;
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

		// Gstreamer callbacks

		static void OnPadAdded(GstElement* element, GstPad* pad, gpointer data);
		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);

		// Modules control

		bool Init();
		void SetEqualizerData();
		gint64 GetCurrentPosition();
		gint64 GetCurrentDuration();
		void Seek(gint64 nanoseconds);
	};
}

#endif // AUDIOPLAYER_HPP

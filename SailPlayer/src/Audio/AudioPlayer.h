#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <QTimer>
#include <gst/gst.h>
#include "AudioResource.h"
#include "AudioPlayerState.h"

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

	public:
		AudioPlayer();
		~AudioPlayer();

		// Player controls

		Q_INVOKABLE void play();
		Q_INVOKABLE void pause();
		Q_INVOKABLE void stop();
		Q_INVOKABLE void setFileToPlay(QString fullFilePath);
		Q_INVOKABLE void seek(int seconds);
		Q_INVOKABLE bool hasFileToPlay() { return !_fileToPlayFullFilePath.isNull() && !_fileToPlayFullFilePath.isEmpty(); }
		Q_INVOKABLE bool isStopped() { return _currentState == Ready; }
		Q_INVOKABLE void resetCurrentFile() { _fileToPlayFullFilePath = QString(); }

	public slots:
		void OnAudioResourceAquireStateChanged(bool acquired);
		void OnEndOfStream();

	signals:
		void getCurrentPosition(int seconds);
		void endOfStream();

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

		// Callbacks

		static void OnPadAdded(GstElement* element, GstPad* pad, gpointer data);
		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);

		bool Init();
		void SetEqualizerData();

		gint64 GetCurrentPosition();
		void Seek(gint64 nanoseconds);
	};
}

#endif // AUDIOPLAYER_H

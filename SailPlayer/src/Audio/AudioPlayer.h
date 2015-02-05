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
		Q_INVOKABLE void setTrackToPlay(QString fullFilePath);
		Q_INVOKABLE void seek(int seconds);

	public slots:
		void OnAudioResourceAquireStateChanged(bool acquired);

	signals:
		void getCurrentPosition(int seconds);

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
		QString _trackToPlayFullFilePath;

		// Callbacks

		static void OnPadAdded(GstElement* element, GstPad* pad, gpointer data);
		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer user_data);

		bool Init();
		void SetEqualizerData();

		gint64 GetCurrentPosition();
		void Seek(gint64 nanoseconds);
	};
}

#endif // AUDIOPLAYER_H

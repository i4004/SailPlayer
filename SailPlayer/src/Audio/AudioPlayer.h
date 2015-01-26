#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
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

		Q_INVOKABLE bool Init();
		Q_INVOKABLE void play();
		Q_INVOKABLE void pause();
		Q_INVOKABLE void stop();

	public slots:
		void OnAudioResourceAquireStateChanged(bool acquired);

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
		bool _needToAcquire;

		// Equalizer

		static int EqualizerBandsNumber;
		GstEqualizerBandState _equalizerData[];

		// Callbacks

		static void OnPadAdded(GstElement* element, GstPad* pad, gpointer data);
		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer user_data);

		void SetEqualizerData();
	};
}

#endif // AUDIOPLAYER_H

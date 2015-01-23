#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <gst/gst.h>
#include "AudioResource.h"
#include "AudioPlayerState.h"

namespace Audio
{
	class AudioPlayer : public QObject
	{
		Q_OBJECT

	public:
		AudioPlayer();
		~AudioPlayer();

		Q_INVOKABLE void play();	
		Q_INVOKABLE void pause();
		Q_INVOKABLE void stop();

	private:
		GstElement* _pipeline;
		GstElement* _source;
		GstElement* _decoder;
		GstElement* _volume;
		GstElement* _sink;

		AudioPlayerState _currentState;
		bool _pausedByResourceBlock;

		static void OnPadAdded(GstElement* element, GstPad* pad, gpointer data);
		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer user_data);
		void OnAudioResourceStateChanged(bool acquired);
		bool Init();
	};
}

#endif // AUDIOPLAYER_H

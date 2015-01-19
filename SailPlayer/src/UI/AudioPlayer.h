#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <gst/gst.h>
#include <QtMultimedia/QMediaPlayer>

namespace UI
{
	class AudioPlayer : public QObject
	{
		Q_OBJECT

	public:
		AudioPlayer();
		~AudioPlayer();

		Q_INVOKABLE void play();
		Q_INVOKABLE void stop();

	private:
		GstElement* _pipeline;
		GstElement* _source;
		GstElement* _decoder;
		GstElement* _volume;
		GstElement* _convert;
		GstElement* _sink;

		static void OnPadAdded(GstElement* element, GstPad* pad, gpointer data);
		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer user_data);
		bool Init();
	};
}

#endif // AUDIOPLAYER_H

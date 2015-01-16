#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QObject>
#include <gst/gst.h>

namespace UI
{
	typedef struct _gstream
	{
		GstElement* pipeline;
		GstBus* bus;
	} GStream;

	class AudioPlayer : public QObject
	{
		Q_OBJECT

	public:
		AudioPlayer();
		~AudioPlayer();

		Q_INVOKABLE void play();

	private:
		GStream gstream;
	};
}

#endif // AUDIOPLAYER_H

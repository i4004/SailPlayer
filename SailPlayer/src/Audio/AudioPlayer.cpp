#include "AudioPlayer.h"
#include <QObject>
#include <QDebug>

namespace Audio
{
	AudioPlayer::AudioPlayer()
	{
		_pausedByResourceBlock = false;
		_currentState = Ready;
		_needToAcquire = true;

		gst_init(NULL, NULL);

		_audioResource = new AudioResource();
		_audioResource->Init();

		QObject::connect(_audioResource, SIGNAL(OnAquireStateChanged(bool)), this, SLOT(OnAudioResourceAquireStateChanged(bool)));
	}

	AudioPlayer::~AudioPlayer()
	{
		gst_element_set_state(_pipeline, GST_STATE_NULL);

		_audioResource->Free();

		gst_object_unref(GST_OBJECT(_pipeline));

		delete _audioResource;
	}

	void AudioPlayer::OnAudioResourceAquireStateChanged(bool acquired)
	{
		if(acquired)
		{
			if(_currentState == Paused && _pausedByResourceBlock)
				play();
		}
		else if(_currentState == Playing)
		{
			pause();

			_pausedByResourceBlock = true;
		}
	}

	void AudioPlayer::OnPadAdded(GstElement* element, GstPad* pad, gpointer data)
	{
		Q_UNUSED(element);

		GstElement* sink = (GstElement*) data;

		GstPad* sinkpad = gst_element_get_static_pad(sink, "sink");
		gst_pad_link(pad, sinkpad);
		gst_object_unref(sinkpad);
	}

	gboolean AudioPlayer::OnBusCall(GstBus* bus, GstMessage* msg, gpointer user_data)
	{
		Q_UNUSED(bus);
		Q_UNUSED(user_data);

		switch (GST_MESSAGE_TYPE (msg))
		{
			case GST_MESSAGE_EOS:
			  break;

			case GST_MESSAGE_ERROR:
			{
				gchar  *debug;
				GError *error;

				gst_message_parse_error (msg, &error, &debug);
				g_free (debug);

				qDebug() << "Error:" << error->message;
				g_error_free (error);
				break;
			}

			default:
				break;
		}

		return TRUE;
	}

	bool AudioPlayer::Init()
	{
		_pipeline = gst_pipeline_new("audio-player");
		_source = gst_element_factory_make("filesrc", NULL);
		_decoder = gst_element_factory_make("decodebin", NULL);
//		_volume = gst_element_factory_make("volume", NULL);
		_sink = gst_element_factory_make("autoaudiosink", NULL);

		if (!_pipeline || !_source || !_decoder || !_sink)
		{
			g_warning("Failed to initialize elements!");
			return false;
		}

		GstBus* bus = gst_pipeline_get_bus(GST_PIPELINE(_pipeline));
		gst_bus_add_watch(bus, OnBusCall, NULL);
		gst_object_unref(bus);

		gst_bin_add_many(GST_BIN(_pipeline), _source, _decoder, _sink, NULL);

		if (!gst_element_link(_source, _decoder))
		{
			g_warning("Failed to link elements!");
			return false;
		}

		g_signal_connect(_decoder, "pad-added", G_CALLBACK(OnPadAdded), _sink);

		g_object_set(G_OBJECT(_source), "location", "/home/nemo/Music/Passage.ogg", NULL);
		//		g_object_set(G_OBJECT(_volume), "volume", 1, NULL);

		return true;
	}

	void AudioPlayer::play()
	{\
		if(_needToAcquire)
			_audioResource->Acquire();

		_currentState = Playing;
		gst_element_set_state(_pipeline, GST_STATE_PLAYING);
	}

	void AudioPlayer::stop()
	{
		gst_element_set_state (_pipeline, GST_STATE_READY);
		_currentState = Ready;
		_needToAcquire = true;
		_audioResource->Release();
	}

	void AudioPlayer::pause()
	{
		_pausedByResourceBlock = false;
		gst_element_set_state (_pipeline, GST_STATE_PAUSED);
		_currentState = Paused;
		_needToAcquire = false;
	}
}
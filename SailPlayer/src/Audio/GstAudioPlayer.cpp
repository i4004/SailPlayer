#include "GstAudioPlayer.hpp"

namespace Audio
{
	GstAudioPlayer::GstAudioPlayer()
	{
//		_gstTimeFormat = GST_FORMAT_TIME;
//		_pausedByResourceBlock = false;

		gst_init(NULL, NULL);

//		connect(_audioResource, SIGNAL(AquireStateChanged(bool)), this, SLOT(OnAudioResourceAquireStateChanged(bool)));
		Init();
	}

	GstAudioPlayer::~GstAudioPlayer()
	{
//		gst_element_set_state(_pipeline, GST_STATE_NULL);

//		_audioResource->Disconnect();

//		gst_object_unref(GST_OBJECT(_pipeline));
	}

	// Player controls

//	void AudioPlayerBase::Play()
//	{
//		_audioResource->Connect();

//		gst_element_set_state(_pipeline, GST_STATE_PLAYING);
//	}

//	void AudioPlayerBase::Pause()
//	{
//		_pausedByResourceBlock = false;

//		gst_element_set_state (_pipeline, GST_STATE_PAUSED);

////		_audioResource->Disconnect();
//	}

//	void AudioPlayerBase::Stop()
//	{
//		gst_element_set_state (_pipeline, GST_STATE_READY);

//		_audioResource->Disconnect();
//	}

//	void AudioPlayerBase::OnStreamStart()
//	{
//	}

//	void AudioPlayerBase::OnAsyncDone()
//	{
//	}

//	void AudioPlayerBase::OnEndOfStream()
//	{
//	}

//	void AudioPlayerBase::OnAboutToFinish()
//	{
//	}

//	void AudioPlayerBase::OnErrorMessage(QString message)
//	{
//		Q_UNUSED(message);
//	}

//	// Player internal controls

//	void AudioPlayerBase::Seek(gint64 nanoseconds)
//	{
//		gst_element_seek(_pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, nanoseconds, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE);
//	}

//	gint64 AudioPlayerBase::GetCurrentPosition()
//	{
//		gint64 value;

//		if(gst_element_query_position(_pipeline, _gstTimeFormat, &value))
//			return value;

//		return -1;
//	}

//	void AudioPlayerBase::SetFileToPlay(QString fullFilePath)
//	{
//		g_object_set(_pipeline, "uri", QString("file://" + fullFilePath).toLocal8Bit().data(), NULL);
//	}

//	gint64 AudioPlayerBase::GetCurrentFileDuration()
//	{
//		gint64 value;

//		if(gst_element_query_duration(_pipeline, _gstTimeFormat, &value))
//			return value;

//		return -1;
//	}

	bool GstAudioPlayer::Init()
	{
		_pipeline = gst_parse_launch("playbin", NULL);
		_sink = gst_element_factory_make("autoaudiosink", NULL);

//		if (!_pipeline || !_equalizer || !_sink)
//		{
//			g_warning("Failed to initialize elements!");
//			return false;
//		}

//		// Subscribe to pipeline messages

//		GstBus* bus = gst_pipeline_get_bus(GST_PIPELINE(_pipeline));
//		gst_bus_add_watch(bus, OnBusCall, this);
//		gst_object_unref(bus);

//		// Initializing additional plugins bin

//		_additionalPlugins = gst_bin_new("additional_plugins");
//		gst_bin_add_many(GST_BIN(_additionalPlugins), _equalizer, _sink, NULL);

//		if (!gst_element_link_many(_equalizer, _sink, NULL))
//		{
//			g_warning("Failed to link elements!");
//			return false;
//		}

//		// Connecting with additional plugins bin

//		GstPad* pad = gst_element_get_static_pad(_equalizer, "sink");
//		GstPad* ghost_pad = gst_ghost_pad_new("sink", pad);
//		gst_pad_set_active(ghost_pad, TRUE);
//		gst_element_add_pad(_additionalPlugins, ghost_pad);
//		gst_object_unref(pad);

//		g_object_set(GST_OBJECT(_pipeline), "audio-sink", _additionalPlugins, NULL);

//		SetEqualizerData();

//		// Subsribe to next track gapless playing handling
//		g_signal_connect(_pipeline, "about-to-finish", G_CALLBACK(OnPipelineAboutToFinish), this);

		return true;
	}


//	gboolean AudioPlayerBase::OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData)
//	{
//		Q_UNUSED(bus);

//		switch (GST_MESSAGE_TYPE (msg))
//		{
//			case GST_MESSAGE_EOS:
//			{
//				static_cast<AudioPlayerBase*>(userData)->OnEndOfStream();
//				break;
//			}

//			case GST_MESSAGE_ASYNC_DONE:
//			{
//				static_cast<AudioPlayerBase*>(userData)->OnAsyncDone();
//				break;
//			}

//			case GST_MESSAGE_STREAM_START:
//			{
//				static_cast<AudioPlayerBase*>(userData)->OnStreamStart();
//				break;
//			}

//			case GST_MESSAGE_ERROR:
//			{
//				gchar* debug;
//				GError* error;

//				gst_message_parse_error (msg, &error, &debug);
//				g_free (debug);

//				static_cast<AudioPlayerBase*>(userData)->OnErrorMessage(error->message);
//				g_error_free (error);
//				break;
//			}

//			default:
//				break;
//		}

//		return TRUE;
//	}

//	void AudioPlayerBase::OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData)
//	{
//		Q_UNUSED(pipeline);

//		static_cast<AudioPlayerBase*>(userData)->OnAboutToFinish();
//	}

//	void AudioPlayerBase::OnAudioResourceAquireStateChanged(bool acquired)
//	{
//		if(acquired)
//		{
//			if(_currentState == AudioPlayerEnums::Paused && _pausedByResourceBlock)
//				Play();
//		}
//		else if(_currentState == AudioPlayerEnums::Playing)
//		{
//			Pause();

//			_pausedByResourceBlock = true;
//		}
//	}
}

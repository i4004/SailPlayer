#include <QObject>
#include <QDebug>

#include "AudioPlayer.hpp"

const int SecondsConvertion = 1000000000;

namespace Audio
{
	int AudioPlayer::EqualizerBandsNumber = 5;

	AudioPlayer::AudioPlayer()
	{
		_pausedByResourceBlock = false;
		_currentState = Ready;
		_fileToPlayFullFilePath = "";
		_gstTimeFormat = GST_FORMAT_TIME;
		_currentPositionTimer.setTimerType(Qt::VeryCoarseTimer);
		_currentPositionTimer.setInterval(1000);

		gst_init(NULL, NULL);

		_audioResource = new AudioResource();

		connect(_audioResource, SIGNAL(AquireStateChanged(bool)), this, SLOT(OnAudioResourceAquireStateChanged(bool)));
		connect(&_currentPositionTimer, SIGNAL(timeout()), this, SLOT(OnCurrentPositionTimerCallback()));

		Init();
	}

	AudioPlayer::~AudioPlayer()
	{
		gst_element_set_state(_pipeline, GST_STATE_NULL);

		_audioResource->Disconnect();

		gst_object_unref(GST_OBJECT(_pipeline));

		delete _audioResource;
	}

	void AudioPlayer::OnPadAdded(GstElement* element, GstPad* pad, gpointer data)
	{
		Q_UNUSED(element);

		GstElement* sink = (GstElement*) data;

		GstPad* sinkpad = gst_element_get_static_pad(sink, "sink");
		gst_pad_link(pad, sinkpad);
		gst_object_unref(sinkpad);
	}

	gboolean AudioPlayer::OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData)
	{
		Q_UNUSED(bus);

		switch (GST_MESSAGE_TYPE (msg))
		{
			case GST_MESSAGE_EOS:
			{
				AudioPlayer* player = static_cast<AudioPlayer*>(userData);
				player->OnEndOfStreamReached();
				break;
			}

			case GST_MESSAGE_ASYNC_DONE:
			{
				AudioPlayer* player = static_cast<AudioPlayer*>(userData);
				player->OnAsyncDone();
				break;
			}

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

	void AudioPlayer::OnEndOfStreamReached()
	{
		emit endOfStreamReached();
	}

	void AudioPlayer::OnAsyncDone()
	{
		if(_currentState == Playing || _currentState == Paused)
			emit currentDurationUpdated(GetCurrentDuration() / SecondsConvertion);
	}

	void AudioPlayer::play()
	{\
		_audioResource->Connect();

		_currentState = Playing;

		emit stateChanged(Playing);

		gst_element_set_state(_pipeline, GST_STATE_PLAYING);

		_currentPositionTimer.start();
	}

	void AudioPlayer::pause()
	{
		_pausedByResourceBlock = false;
		gst_element_set_state (_pipeline, GST_STATE_PAUSED);
		_currentState = Paused;
		emit stateChanged(Paused);

		_currentPositionTimer.stop();
	}

	void AudioPlayer::stop()
	{
		gst_element_set_state (_pipeline, GST_STATE_READY);
		_currentState = Ready;

		emit stateChanged(Ready);
		emit currentPositionUpdated(0);
		emit currentDurationUpdated(0);

		_currentPositionTimer.stop();

		_audioResource->Disconnect();
	}

	void AudioPlayer::setFileToPlay(QString fullFilePath)
	{
		_fileToPlayFullFilePath = fullFilePath;
		g_object_set(G_OBJECT(_source), "location", _fileToPlayFullFilePath.toLocal8Bit().data(), NULL);
	}

	void AudioPlayer::seek(int seconds)
	{
		Seek(gint64(seconds) * SecondsConvertion);
	}

	void AudioPlayer::OnCurrentPositionTimerCallback()
	{
		emit currentPositionUpdated(GetCurrentPosition() / SecondsConvertion);
	}

	bool AudioPlayer::Init()
	{
		_pipeline = gst_pipeline_new("audio-player");
		_source = gst_element_factory_make("filesrc", NULL);
		_decoder = gst_element_factory_make("decodebin", NULL);
		_equalizer = gst_element_factory_make("equalizer-nbands", NULL);
		_sink = gst_element_factory_make("autoaudiosink", NULL);

		if (!_pipeline || !_source || !_decoder || !_equalizer || !_sink)
		{
			g_warning("Failed to initialize elements!");
			return false;
		}

		GstBus* bus = gst_pipeline_get_bus(GST_PIPELINE(_pipeline));
		gst_bus_add_watch(bus, OnBusCall, this);
		gst_object_unref(bus);

		gst_bin_add_many(GST_BIN(_pipeline), _source, _decoder, _equalizer, _sink, NULL);

		if (!gst_element_link(_source, _decoder) || !gst_element_link(_equalizer, _sink))
		{
			g_warning("Failed to link elements!");
			return false;
		}

		g_signal_connect(_decoder, "pad-added", G_CALLBACK(OnPadAdded), _equalizer);

		g_object_set (G_OBJECT (_equalizer), "num-bands", EqualizerBandsNumber, NULL);

		SetEqualizerData();

		return true;
	}

	void AudioPlayer::SetEqualizerData()
	{
		gint i;
		GstObject *band;

		// TODO
		GstEqualizerBandState equalizerData[] = {
			{ 120.0,	5.0,	0 },
			{ 500.0,	2.0,	0 },
			{ 1503.0,	2.0,	0 },
			{ 6000.0,	2.0,	0 },
			{ 3000.0,	120.0,	0 }
		};

		for (i = 0; i < EqualizerBandsNumber; i++)
		{
			band = gst_child_proxy_get_child_by_index(GST_CHILD_PROXY(_equalizer), i);
			g_object_set(G_OBJECT(band), "freq", equalizerData[i].freq, "bandwidth", equalizerData[i].width, "gain", equalizerData[i].gain, NULL);

			g_object_unref(G_OBJECT(band));
		}
	}

	gint64 AudioPlayer::GetCurrentPosition()
	{
		gint64 value;

		if(gst_element_query_position(_pipeline, &_gstTimeFormat, &value))
			return value;

		return 0;
	}

	gint64 AudioPlayer::GetCurrentDuration()
	{
		gint64 value;

		if(gst_element_query_duration(_pipeline, &_gstTimeFormat, &value))
			return value;

		return 0;
	}

	void AudioPlayer::Seek(gint64 nanoseconds)
	{
		gst_element_seek(_pipeline, 1.0, GST_FORMAT_TIME, GST_SEEK_FLAG_FLUSH, GST_SEEK_TYPE_SET, nanoseconds, GST_SEEK_TYPE_NONE, GST_CLOCK_TIME_NONE);
	}
}

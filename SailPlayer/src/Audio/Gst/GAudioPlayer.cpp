#include "GAudioPlayer.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Audio
{
	namespace Gst
	{
		GAudioPlayer::GAudioPlayer(GBus* bus, GPipeline* pipeline)
		{
			_bus = bus;
			_pipeline = pipeline;

	//		_gstTimeFormat = GST_FORMAT_TIME;
	//		_pausedByResourceBlock = false;

	//		connect(_audioResource, SIGNAL(AquireStateChanged(bool)), this, SLOT(OnAudioResourceAquireStateChanged(bool)));

			if(!Init())
			{

			}
		}

		GAudioPlayer::~GAudioPlayer()
		{
	//		_audioResource->Disconnect();
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

	//	gint64 AudioPlayerBase::GetCurrentFileDuration()
	//	{
	//		gint64 value;

	//		if(gst_element_query_duration(_pipeline, _gstTimeFormat, &value))
	//			return value;

	//		return -1;
	//	}

		bool GAudioPlayer::Init()
		{
	//		SetEqualizerData();

	//		// Subsribe to next track gapless playing handling
	//		g_signal_connect(_pipeline, "about-to-finish", G_CALLBACK(OnPipelineAboutToFinish), this);

			return true;
		}

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
}
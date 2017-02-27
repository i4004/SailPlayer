#ifndef GSTAUDIOPLAYER_HPP
#define GSTAUDIOPLAYER_HPP

#include <gst/gst.h>

//#include "AudioPlayerEnums.hpp"
#include "AudioPlayerBase.hpp"

namespace Audio
{
	class GstAudioPlayer : public AudioPlayerBase
	{
	public:
		GstAudioPlayer();
		~GstAudioPlayer();

//		virtual void OnStreamStart();
//		virtual void OnAsyncDone();
//		virtual void OnAboutToFinish();
//		virtual void OnEndOfStream();
//		virtual void OnErrorMessage(QString message);

//	protected:
//		void Seek(gint64 nanoseconds);
//		void SetFileToPlay(QString fullFilePath);

//		gint64 GetCurrentPosition();
//		gint64 GetCurrentFileDuration();

	private:
		// Audio resoure and modules

		GstElement* _pipeline;
		GstElement* _additionalPlugins;
		GstElement* _sink;

//		GstFormat _gstTimeFormat;

//		// Current state

//		bool _pausedByResourceBlock;

//		// Equalizer

//		GstEqualizerBandState _equalizerData[];

		bool Init();
//		void SetEqualizerData();

//		// Gstreamer callbacks

//		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);
//		static void OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData);

//	private slots:
//		void OnAudioResourceAquireStateChanged(bool acquired);
	};
}

#endif // AUDIOPLAYER_HPP

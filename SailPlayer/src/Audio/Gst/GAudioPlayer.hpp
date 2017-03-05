#ifndef GAUDIOPLAYER_HPP
#define GAUDIOPLAYER_HPP

#include "GBus.hpp"
#include "GPipeline.hpp"
#include "GEqualizer.hpp"

//#include "AudioPlayerEnums.hpp"
//#include "AudioPlayerBase.hpp"

namespace Audio
{
	namespace Gst
	{
		class GAudioPlayer// : public AudioPlayerBase
		{
		public:
			GAudioPlayer(GBus* bus, GPipeline* pipeline);
			~GAudioPlayer();

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
			GBus* _bus;
			GPipeline* _pipeline;
			GEqualizer* _equalizer;

	//		GstElement* _additionalPlugins;

	//		GstFormat _gstTimeFormat;

	//		// Current state

	//		bool _pausedByResourceBlock;

	//		// Equalizer

	//		GstEqualizerBandState _equalizerData[];

			bool Init();

	//		// Gstreamer callbacks

	//		static void OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData);

	//	private slots:
	//		void OnAudioResourceAquireStateChanged(bool acquired);
		};
	}
}

#endif // GAUDIOPLAYER_HPP

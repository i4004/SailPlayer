#ifndef GAUDIOPLAYER_HPP
#define GAUDIOPLAYER_HPP

#include "../AudioPlayerBase.hpp"
#include "GBus.hpp"
#include "GPipeline.hpp"
#include "GEqualizer.hpp"

//#include "AudioPlayerEnums.hpp"

namespace Audio
{
	namespace Gst
	{
		class GAudioPlayer : public AudioPlayerBase
		{
		public:
			GAudioPlayer(GBus* bus, GPipeline* pipeline);
			~GAudioPlayer();

			virtual void Play();
			virtual void Pause();
			virtual void Stop();

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

	//		GstFormat _gstTimeFormat;

	//		// Gstreamer callbacks

	//		static void OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData);

	//	private slots:
	//		void OnAudioResourceAquireStateChanged(bool acquired);
		};
	}
}

#endif // GAUDIOPLAYER_HPP

#ifndef AUDIOPLAYER_HPP
#define AUDIOPLAYER_HPP

#include <gst/gst.h>

//#include "AudioPlayerEnums.hpp"
#include "AudioResource.hpp"
//#include "GstEqualizerBandState.hpp"

namespace Audio
{
	class AudioPlayer// : public QObject
	{
//		Q_OBJECT
//		Q_PROPERTY(Audio::AudioPlayerEnums::AudioPlayerState state READ GetCurrentState NOTIFY StateChanged)

	public:
		AudioPlayer(AudioResource* audioResource);
		~AudioPlayer();

//		// Player controls

//		virtual void Play();
//		virtual void Pause();
//		virtual void Stop();

//		AudioPlayerEnums::AudioPlayerState GetCurrentState() { return _currentState; }

//		virtual void OnStreamStart();
//		virtual void OnAsyncDone();
//		virtual void OnAboutToFinish();
//		virtual void OnEndOfStream();
//		virtual void OnErrorMessage(QString message);

//	signals:
//		void StateChanged(AudioPlayerEnums::AudioPlayerState state);

//	protected:
//		void Seek(gint64 nanoseconds);
//		void SetFileToPlay(QString fullFilePath);

//		gint64 GetCurrentPosition();
//		gint64 GetCurrentFileDuration();

	private:
		// Audio resoure and modules

		AudioResource* _audioResource;

//		GstElement* _pipeline;
//		GstElement* _additionalPlugins;
//		GstElement* _equalizer;
//		GstElement* _sink;

//		GstFormat _gstTimeFormat;

//		// Current state

//		AudioPlayerEnums::AudioPlayerState _currentState;
//		bool _pausedByResourceBlock;

//		// Equalizer

//		static int EqualizerBandsNumber;
//		GstEqualizerBandState _equalizerData[];

//		bool Init();
//		void SetEqualizerData();

//		// Gstreamer callbacks

//		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);
//		static void OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData);

//	private slots:
//		void OnAudioResourceAquireStateChanged(bool acquired);
	};
}

#endif // AUDIOPLAYER_HPP

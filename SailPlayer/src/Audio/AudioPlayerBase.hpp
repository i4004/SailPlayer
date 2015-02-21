#ifndef AUDIOPLAYERBASE_HPP
#define AUDIOPLAYERBASE_HPP

#include <QDebug>

#include <gst/gst.h>

#include "AudioResource.hpp"

namespace Audio
{
	typedef struct
	{
		gfloat freq;
		gfloat width;
		gfloat gain;
	} GstEqualizerBandState;

	class AudioPlayerBase : public QObject
	{
		Q_OBJECT
		Q_ENUMS(AudioPlayerState)
		Q_PROPERTY(AudioPlayerState state READ getCurrentState NOTIFY stateChanged)

	public:
		AudioPlayerBase();
		~AudioPlayerBase();

		enum AudioPlayerState
		{
			Ready = 0,
			Paused = 1,
			Playing = 2
		};

		// Player controls

		Q_INVOKABLE virtual void play();
		Q_INVOKABLE virtual void pause();
		Q_INVOKABLE virtual void stop();
		Q_INVOKABLE AudioPlayerState getCurrentState() { return _currentState; }

		virtual void OnStreamStart();
		virtual void OnAsyncDone();
		virtual void OnAboutToFinish();
		virtual void OnEndOfStream();
		virtual void OnErrorMessage(QString message);

	signals:
		void stateChanged(AudioPlayerBase::AudioPlayerState state);

	protected:
		// Player internal controls

		void Seek(gint64 nanoseconds);
		gint64 GetCurrentPosition();
		void SetFileToPlay(QString fullFilePath);
		gint64 GetCurrentFileDuration();

	private:
		// Audio resoure and modules

		AudioResource* _audioResource;

		GstElement* _pipeline;
		GstElement* _additionalPlugins;
		GstElement* _equalizer;
		GstElement* _sink;

		GstFormat _gstTimeFormat;

		// Current state

		AudioPlayerState _currentState;
		bool _pausedByResourceBlock;

		// Equalizer

		static int EqualizerBandsNumber;
		GstEqualizerBandState _equalizerData[];

		bool Init();
		void SetEqualizerData();

		// Gstreamer callbacks

		static gboolean OnBusCall(GstBus* bus, GstMessage* msg, gpointer userData);
		static void OnPipelineAboutToFinish(GstElement* pipeline, gpointer userData);

	private slots:
		void OnAudioResourceAquireStateChanged(bool acquired);
	};
}

#endif // AUDIOPLAYERBASE_HPP

#ifndef AUDIORRSOIRCE_HPP
#define AUDIORRSOIRCE_HPP

#include <QObject>
#include <audioresource.h>

namespace Audio
{
	class AudioResource : public QObject
	{
		Q_OBJECT

	public:
		AudioResource();
		~AudioResource();

		bool Connect();
		bool Disconnect();

		bool IsConnected() { return _isConnected; }

	public slots:
		void SetAcquireState(bool acquired);

	signals:
		void AquireStateChanged(bool acquired);

	private:
		audioresource_t* _resource;
		bool _audioResourceGotReply;
		bool _audioResourceAcquired;
		bool _isConnected;

		void WaitForAnAudioResourceCallback();

		static void OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData);
	};
}

#endif // AUDIORRSOIRCE_HPP

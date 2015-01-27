#ifndef AUDIORRSOIRCE_H
#define AUDIORRSOIRCE_H

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

		void WaitForAnAudioResourceCallback();

		bool Connect();
		bool Disconnect();

		bool IsConnected() { return _isConnected; }

	public slots:
		void SetAcquireState(bool acquired);

	signals:
		void OnAquireStateChanged(bool acquired);

	private:
		audioresource_t* _resource;
		bool _audioResourceGotReply;
		bool _audioResourceAcquired;
		bool _isConnected;

		static void OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData);
	};
}

#endif // AUDIORRSOIRCE_H

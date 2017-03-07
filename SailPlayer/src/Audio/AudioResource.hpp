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

		void Acquire();
		void Release();

	public slots:
		void SetAcquired(bool acquired);

	signals:
		void AquiredChanged(bool acquired);

	private:
		audioresource_t* _resource;

		bool _acquired;

		static void OnAudioResourceCallback(audioresource_t* audioResource, bool acquired, void* userData);
	};
}

#endif // AUDIORRSOIRCE_HPP

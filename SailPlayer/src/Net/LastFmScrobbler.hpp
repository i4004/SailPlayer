#ifndef LASTFMSCROBBLER_HPP
#define LASTFMSCROBBLER_HPP

#include <QObject>

namespace Net
{
	class LastFmScrobbler  : public QObject
	{
		Q_OBJECT
		Q_PROPERTY(QString apiKey READ GetApiKey WRITE SetApiKey)
		Q_PROPERTY(QString secret READ GetSecret WRITE SetSecret)

	public:
		LastFmScrobbler();

		QString GetApiKey() { return _apiKey; }
		void SetApiKey(QString key) { _apiKey = key; }

		QString GetSecret() { return _secret; }
		void SetSecret(QString secret) { _secret = secret; }

	private:
		QString _apiKey;
		QString _secret;
	};
}

#endif // LASTFMSCROBBLER_HPP

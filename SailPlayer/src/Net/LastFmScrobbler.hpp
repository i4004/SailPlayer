#ifndef LASTFMSCROBBLER_HPP
#define LASTFMSCROBBLER_HPP

#include <QObject>
#include <QMap>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkAccessManager>

namespace Net
{
	class LastFmScrobbler  : public QObject
	{
		Q_OBJECT
		Q_PROPERTY(QString apiKey READ GetApiKey WRITE SetApiKey)
		Q_PROPERTY(QString secret READ GetSecret WRITE SetSecret)

	public:
		LastFmScrobbler();
		~LastFmScrobbler();

		QString GetApiKey() { return _apiKey; }
		void SetApiKey(QString key) { _apiKey = key; }

		QString GetSecret() { return _secret; }
		void SetSecret(QString secret) { _secret = secret; }

		Q_INVOKABLE void authenticate(QString userName, QString password);

	private:
		QUrl _apiRootUrl;
		QString _apiKey;
		QString _secret;

		QNetworkAccessManager* _networkAccessManager;

		QUrlQuery MakeQuery(QString method, QMap<QString, QString> queryVariables);
		void SendRequest(QString method, QMap<QString, QString> queryVariables);

	private slots:
		void OnNetworkAccessManagerReply(QNetworkReply*);

	};
}

#endif // LASTFMSCROBBLER_HPP

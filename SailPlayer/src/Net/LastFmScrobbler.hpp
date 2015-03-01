#ifndef LASTFMSCROBBLER_HPP
#define LASTFMSCROBBLER_HPP

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDomDocument>

#include "LastFmQueryBuilder.hpp"

namespace Net
{
	class LastFmScrobbler  : public QObject
	{
		Q_OBJECT
		Q_ENUMS(LastFmError)
		Q_PROPERTY(QString apiKey READ GetApiKey WRITE SetApiKey)
		Q_PROPERTY(QString secret READ GetSecret WRITE SetSecret)

	public:
		LastFmScrobbler();
		~LastFmScrobbler();

		enum LastFmError
		{
			Undefined = 0,
			NoInternetConnection = 1,
			InvalidService = 2,
			InvalidMethod = 3,
			AuthenticationFailed = 4,
			InvalidFormat = 5,
			znvalidParameters = 6,
			InvalidResource = 7,
			OperationFailed = 8,
			InvalidSessionKey = 9,
			InvalidApiKey = 10,
			ServiceOffline = 11,
			InvalidMethodSignatureSupplied = 13,
			TemporaryProcessingError = 16,
			SuspendedApiKey = 26,
			RateLimitExceeded = 29
		};

		QString GetApiKey() { return _apiKey; }
		void SetApiKey(QString key) { _apiKey = key; }

		QString GetSecret() { return _secret; }
		void SetSecret(QString secret) { _secret = secret; }

		Q_INVOKABLE void authenticate(QString userName, QString password);

	signals:
			void authenticated(QString sessionKey);
			void errorResponse(LastFmError error, QString description);

	private:
		LastFmQueryBuilder _queryBuilder;

		QUrl _apiRootUrl;
		QString _apiKey;
		QString _secret;

		QNetworkAccessManager* _networkAccessManager;

		void SendRequest(QString method, QMap<QString, QString> queryVariables);

		void ProcessOkReplyData(QDomElement lfmElement);
		void ProcessFailedReplyData(QDomElement lfmElement);

	private slots:
		void OnNetworkAccessManagerReply(QNetworkReply*);

	};
}

#endif // LASTFMSCROBBLER_HPP

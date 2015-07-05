#ifndef LASTFMSCROBBLER_HPP
#define LASTFMSCROBBLER_HPP

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDomDocument>

#include "../Playlist/Track.hpp"

#include "LastFmQueryBuilder.hpp"
#include "LastFmRequestBuilder.hpp"

using namespace Playlist;

namespace Net
{
	class LastFmScrobbler  : public QObject
	{
		Q_OBJECT
		Q_ENUMS(LastFmError)
		Q_PROPERTY(int numberOfScrobbleCacheItems READ GetScrobbleCacheItemsNumber NOTIFY NumberOfScrobbleCacheItemsChanged)

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

		void Authenticate(QString userName, QString password);
		void SendNowPlaying(Track* track);
		bool AddToCache(Track* playedTrack, QDateTime playStartTime);
		void AddToCache(QMap<QDateTime, Track*> tracks);
		void ScrobbleTracksFromCache();
		void ClearCache();

		QString GetSessionKey() { return _sessionKey; }
		QMap<QDateTime, Track*> GetCache(){ return _scrobbleCache; }

	public slots:
		void SetSessionKey(QString key) { _sessionKey = key; }

	signals:
		void Authenticated(QString sessionKey);
		void NowPlaying();
		void ErrorResponse(LastFmError error, QString description);
		void NumberOfScrobbleCacheItemsChanged();
		void TracksSubmitted();

	private:
		LastFmQueryBuilder _queryBuilder;
		LastFmRequestBuilder _requestBuilder;

		QString _sessionKey;

		QMap<QDateTime, Track*> _scrobbleCache;

		QNetworkAccessManager* _networkAccessManager;	

		void SendRequest(QString method, QMap<QString, QString> queryVariables);

		void ProcessOkReplyData(QDomElement lfmElement);
		void ProcessFailedReplyData(QDomElement lfmElement);

		int GetScrobbleCacheItemsNumber() { return _scrobbleCache.count(); }
		void ProcessScrobbleResult(QDomElement scrobblesElement);

	private slots:
		void OnNetworkAccessManagerReply(QNetworkReply*);
	};
}

#endif // LASTFMSCROBBLER_HPP

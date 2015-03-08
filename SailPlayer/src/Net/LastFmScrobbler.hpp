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
//		Q_ENUMS(LastFmError)
//		Q_PROPERTY(int numberOfScrobbleCacheItems READ GetScrobbleCacheItemsNumber NOTIFY numberOfScrobbleCacheItemsChanged)

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

		QString GetSessionKey() { return _sessionKey; }

	public slots:
		void SetSessionKey(QString key) { _sessionKey = key; }

//		Q_INVOKABLE void authenticate(QString userName, QString password);
//		Q_INVOKABLE void sendNowPlaying(QObject* currentPlayingTrack);
//		Q_INVOKABLE void scrobbleTrack(QObject* playedTrack, QDateTime playStartTime);

//		Q_INVOKABLE void submitTracksFromCache();
//		Q_INVOKABLE void loadSavedTracksToCache();
//		Q_INVOKABLE void saveCachedTracks();

//	signals:
//		void authenticated(QString sessionKey);
//		void nowPlaying();
//		void errorResponse(LastFmError error, QString description);
//		void numberOfScrobbleCacheItemsChanged();
//		void tracksSubmitted();

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

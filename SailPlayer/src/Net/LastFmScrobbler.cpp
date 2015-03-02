#include "LastFmScrobbler.hpp"

namespace Net
{
	LastFmScrobbler::LastFmScrobbler()
	{
		_networkAccessManager = new QNetworkAccessManager(this);

		 connect(_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(OnNetworkAccessManagerReply(QNetworkReply*)));
	}

	LastFmScrobbler::~LastFmScrobbler()
	{
		qDeleteAll(_scrobbleCache);
		_scrobbleCache.clear();

		delete _networkAccessManager;
	}

	void LastFmScrobbler::authenticate(QString userName, QString password)
	{
		QMap<QString, QString> queryVariables;

		queryVariables["username"] = userName;
		queryVariables["password"] = password;

		SendRequest("auth.getMobileSession", queryVariables);
	}

	void LastFmScrobbler::sendNowPlaying(QObject* currentPlayingTrack)
	{
		if(_sessionKey.isNull() || _sessionKey.isEmpty() || currentPlayingTrack == NULL)
			return;

		Track* track = (Track*)currentPlayingTrack;
		QString artistName = track->GetArtistName();
		QString trackName = track->GetName();
		int trackNumber = track->GetNumber();
		int duration = track->GetDuration() / 1000;

		if(artistName.isNull() || artistName.isEmpty() || trackName.isNull() || trackName.isEmpty())
			return;

		QMap<QString, QString> queryVariables;

		queryVariables["artist"] = artistName;
		queryVariables["track"] = trackName;
		queryVariables["album"] = track->GetAlbumName();

		if(duration > 0)
			queryVariables["duration"] = QString::number(duration);

		if(trackNumber > 0)
			queryVariables["trackNumber"] = QString::number(trackNumber);

		queryVariables["sk"] = _sessionKey;

		SendRequest("track.updateNowPlaying", queryVariables);
	}

	void LastFmScrobbler::scrobbleTrack(QObject* playedTrack, QDateTime playStartTime)
	{
		if(_sessionKey.isNull() || _sessionKey.isEmpty() || playedTrack == NULL)
			return;

		Track* track = new Track(*(Track*)playedTrack);

		_scrobbleCache.insert(playStartTime, track);

		submitTracksFromCache();
	}

	void LastFmScrobbler::submitTracksFromCache()
	{
	}

	void LastFmScrobbler::loadTracksToCache()
	{
		QMap<QDateTime, Track*> tracks = _settings.GetCachedTracks();

		QMap<QDateTime, Track*>::iterator i;

		for (i = tracks.begin(); i != tracks.end(); ++i)
			_scrobbleCache.insert(i.key(), i.value());
	}

	void LastFmScrobbler::saveCachedTracks()
	{
		_settings.SetCachedTracks(_scrobbleCache);
	}

	void LastFmScrobbler::SendRequest(QString method, QMap<QString, QString> queryVariables)
	{
		QUrlQuery query = _queryBuilder.Build(method, _apiKey, _secret, queryVariables);
		QNetworkRequest request = _requestBuilder.Build();

		_networkAccessManager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());
	}

	void LastFmScrobbler::OnNetworkAccessManagerReply(QNetworkReply* reply)
	{
		QNetworkReply::NetworkError error = reply->error();

		if(error == QNetworkReply::NetworkSessionFailedError)
		{
			emit errorResponse(NoInternetConnection, "No internet connection.");
			return;
		}

		if(error == QNetworkReply::HostNotFoundError)
		{
			emit errorResponse(NoInternetConnection, "Host not found or no internet connection.");
			return;
		}

		QDomDocument doc;

		doc.setContent(reply->readAll());

		if(!doc.hasChildNodes())
			emit errorResponse(Undefined, "XML reply is empty.");

		QDomElement root = doc.documentElement();
		QString status = root.attribute("status");

		if(status == "ok")
			ProcessOkReplyData(root);
		else if (status == "failed")
			ProcessFailedReplyData(root);
	}

	void LastFmScrobbler::ProcessOkReplyData(QDomElement lfmElement)
	{
		QDomNodeList sessionList = lfmElement.elementsByTagName("session");
		QDomNodeList nowplayingList = lfmElement.elementsByTagName("nowplaying");

		if(sessionList.count() > 0)
			emit authenticated(sessionList.at(0).toElement().elementsByTagName("key").at(0).toElement().text());
		else if(nowplayingList.count() > 0)
			emit nowPlaying();
	}

	void LastFmScrobbler::ProcessFailedReplyData(QDomElement lfmElement)
	{
		QDomElement errorElement = lfmElement.elementsByTagName("error").at(0).toElement();

		emit errorResponse((LastFmError)errorElement.attribute("code").toInt(), errorElement.text().trimmed());
	}
}

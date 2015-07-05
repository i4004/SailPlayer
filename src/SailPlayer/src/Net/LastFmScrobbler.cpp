#include "../SailPlayerSettings.hpp"

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
		ClearCache();

		delete _networkAccessManager;
	}

	void LastFmScrobbler::Authenticate(QString userName, QString password)
	{
		QMap<QString, QString> queryVariables;

		queryVariables["username"] = userName;
		queryVariables["password"] = password;

		SendRequest("auth.getMobileSession", queryVariables);
	}

	void LastFmScrobbler::SendNowPlaying(Track* track)
	{
		if(_sessionKey.isNull() || _sessionKey.isEmpty() || track == NULL)
			return;

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

	bool LastFmScrobbler::AddToCache(Track* track, QDateTime playStartTime)
	{
		if(_sessionKey.isNull() || _sessionKey.isEmpty() || track == NULL)
			return false;

		QString artistName = track->GetArtistName();
		QString trackName = track->GetName();

		if(artistName.isNull() || artistName.isEmpty() || trackName.isNull() || trackName.isEmpty())
			return false;

		_scrobbleCache.insert(playStartTime.toUTC(), track);

		emit NumberOfScrobbleCacheItemsChanged();

		return true;
	}

	void LastFmScrobbler::AddToCache(QMap<QDateTime, Track *> tracks)
	{
		QMap<QDateTime, Track*>::iterator i;

		for (i = tracks.begin(); i != tracks.end(); ++i)
			_scrobbleCache.insert(i.key(), i.value());

		emit NumberOfScrobbleCacheItemsChanged();
	}

	void LastFmScrobbler::ScrobbleTracksFromCache()
	{
		if(_sessionKey.isNull() || _sessionKey.isEmpty() || _scrobbleCache.count() == 0)
			return;

		QMap<QString, QString> queryVariables;
		QMap<QDateTime, Track*>::iterator i;
		int index = 0;

		for (i = _scrobbleCache.begin(); i != _scrobbleCache.end() && index <= 49; ++i)
		{
			Track* track = i.value();

			QString artistName = track->GetArtistName();
			QString trackName = track->GetName();
			int trackNumber = track->GetNumber();
			int duration = track->GetDuration() / 1000;

			queryVariables[QString("artist[%1]").arg(index)] = artistName;
			queryVariables[QString("track[%1]").arg(index)] = trackName;
			queryVariables[QString("timestamp[%1]").arg(index)] = QString::number(i.key().toTime_t());
			queryVariables[QString("album[%1]").arg(index)] = track->GetAlbumName();
			queryVariables[QString("chosenByUser[%1]").arg(index)] = QString("1");

			if(trackNumber > 0)
				queryVariables[QString("trackNumber[%1]").arg(index)] = QString::number(trackNumber);

			if(duration > 0)
				queryVariables[QString("duration[%1]").arg(index)] = QString::number(duration);

			queryVariables["sk"] = _sessionKey;

			index++;
		}

		SendRequest("track.scrobble", queryVariables);
	}

	void LastFmScrobbler::ClearCache()
	{
		qDeleteAll(_scrobbleCache);
		_scrobbleCache.clear();

		emit NumberOfScrobbleCacheItemsChanged();
	}

	void LastFmScrobbler::SendRequest(QString method, QMap<QString, QString> queryVariables)
	{
		QUrlQuery query = _queryBuilder.Build(method, queryVariables);
		QNetworkRequest request = _requestBuilder.Build();

		_networkAccessManager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());
	}

	void LastFmScrobbler::OnNetworkAccessManagerReply(QNetworkReply* reply)
	{
		QNetworkReply::NetworkError error = reply->error();

		if(error == QNetworkReply::NetworkSessionFailedError)
		{
			emit ErrorResponse(NoInternetConnection, "No internet connection.");
			return;
		}

		if(error == QNetworkReply::HostNotFoundError)
		{
			emit ErrorResponse(NoInternetConnection, "Host not found or no internet connection.");
			return;
		}

		QDomDocument doc;

		doc.setContent(reply->readAll());

		if(!doc.hasChildNodes())
			emit ErrorResponse(Undefined, "XML reply is empty.");

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
		QDomNodeList scrobblesList = lfmElement.elementsByTagName("scrobbles");

		if(sessionList.count() > 0)
			emit Authenticated(sessionList.at(0).toElement().elementsByTagName("key").at(0).toElement().text());
		else if(nowplayingList.count() > 0)
			emit NowPlaying();
		else if(scrobblesList.count() > 0)
			ProcessScrobbleResult(scrobblesList.at(0).toElement());
	}

	void LastFmScrobbler::ProcessFailedReplyData(QDomElement lfmElement)
	{
		QDomElement errorElement = lfmElement.elementsByTagName("error").at(0).toElement();

		emit ErrorResponse((LastFmError)errorElement.attribute("code").toInt(), errorElement.text().trimmed());
	}

	void LastFmScrobbler::ProcessScrobbleResult(QDomElement scrobblesElement)
	{
		int accepted = scrobblesElement.attribute("accepted").toInt();
		int ignored = scrobblesElement.attribute("ignored").toInt();

		QMap<QDateTime, Track*>::iterator i;
		int index = 0;

		for (i = _scrobbleCache.begin(); i != _scrobbleCache.end() && index < accepted + ignored;)
		{
			Track* track = i.value();
			delete track;
			i = _scrobbleCache.erase(i);

			index++;
		}

		emit NumberOfScrobbleCacheItemsChanged();
		emit TracksSubmitted();
	}
}

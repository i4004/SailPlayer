#include <QCryptographicHash>
#include <QNetworkRequest>
#include <QDebug>

#include "LastFmScrobbler.hpp"

namespace Net
{
	LastFmScrobbler::LastFmScrobbler()
	{
		_apiRootUrl = QUrl("https://ws.audioscrobbler.com/2.0/");
		_networkAccessManager = new QNetworkAccessManager(this);

		 connect(_networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(OnNetworkAccessManagerReply(QNetworkReply*)));
	}

	LastFmScrobbler::~LastFmScrobbler()
	{
		delete _networkAccessManager;
	}

	void LastFmScrobbler::authenticate(QString userName, QString password)
	{
		QMap<QString, QString> queryVariables;

		queryVariables["username"] = userName;
		queryVariables["password"] = password;

		SendRequest("auth.getMobileSession", queryVariables);
	}

	QUrlQuery LastFmScrobbler::MakeQuery(QString method, QMap<QString, QString> queryVariables)
	{
		QUrlQuery query;
		QString signatureInput = "";
		QByteArray signatureInputRaw;
		QMap<QString, QString>::iterator i;

		queryVariables.insert("method", method);
		queryVariables.insert("api_key", _apiKey);

		for (i = queryVariables.begin(); i != queryVariables.end(); ++i)
		{
			query.addQueryItem(i.key(), i.value());
			signatureInput += i.key() + i.value();
		}

		signatureInputRaw.append(signatureInput + _secret);

		query.addQueryItem("api_sig", QCryptographicHash::hash(signatureInputRaw, QCryptographicHash::Md5).toHex());
		qDebug() << signatureInputRaw;

		return query;
	}

	void LastFmScrobbler::SendRequest(QString method, QMap<QString, QString> queryVariables)
	{
		QUrlQuery query = MakeQuery(method, queryVariables);
		QNetworkRequest request = QNetworkRequest(_apiRootUrl);

		request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

		_networkAccessManager->post(request, query.toString(QUrl::FullyEncoded).toUtf8());
	}

	void LastFmScrobbler::OnNetworkAccessManagerReply(QNetworkReply* reply)
	{
		QByteArray replyDataRaw = reply->readAll();
		QString replyData = QString(replyDataRaw);

		qDebug() << replyData;
	}
}

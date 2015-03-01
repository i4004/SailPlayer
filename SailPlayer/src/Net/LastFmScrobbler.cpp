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

		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

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

		if(error != QNetworkReply::NoError)
		{
			qDebug() << reply->error();
			emit errorResponse(Undefined, "Network error.");
			return;
		}

		QDomDocument doc;

		doc.setContent(reply->readAll());

		qDebug() << doc.toElement().text();

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

		if(sessionList.count() > 0)
			emit authenticated(sessionList.at(0).toElement().elementsByTagName("key").at(0).toElement().text());
	}

	void LastFmScrobbler::ProcessFailedReplyData(QDomElement lfmElement)
	{
		QDomElement errorElement = lfmElement.elementsByTagName("error").at(0).toElement();

		emit errorResponse((LastFmError)errorElement.attribute("code").toInt(), errorElement.text().trimmed());
	}
}

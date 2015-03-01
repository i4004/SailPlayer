#include <QDebug>

#include "LastFmRequestBuilder.hpp"

namespace Net
{
	QString LastFmRequestBuilder::ApplicationName = "";
	QString LastFmRequestBuilder::ApplicationVersion = "";
	QString LastFmRequestBuilder::ContactUrl = "";

	LastFmRequestBuilder::LastFmRequestBuilder()
	{
		_apiRootUrl = QUrl("https://ws.audioscrobbler.com/2.0/");
	}

	QNetworkRequest LastFmRequestBuilder::Build()
	{
		QNetworkRequest request = QNetworkRequest(_apiRootUrl);

		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
		request.setHeader(QNetworkRequest::UserAgentHeader, QString("%1/%2 (%3)").arg(ApplicationName, ApplicationVersion, ContactUrl));

		return request;
	}
}

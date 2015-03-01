#include "LastFmRequestBuilder.hpp"

namespace Net
{
	LastFmRequestBuilder::LastFmRequestBuilder()
	{
		_apiRootUrl = QUrl("https://ws.audioscrobbler.com/2.0/");
	}

	QNetworkRequest LastFmRequestBuilder::Build()
	{
		QNetworkRequest request = QNetworkRequest(_apiRootUrl);

		request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

		return request;
	}
}

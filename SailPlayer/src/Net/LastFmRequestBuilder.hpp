#ifndef LASTFMREQUESTBUILDER_HPP
#define LASTFMREQUESTBUILDER_HPP

#include <QNetworkRequest>

namespace Net
{
	class LastFmRequestBuilder
	{
	public:
		LastFmRequestBuilder();

		QNetworkRequest Build();

	private:
		QUrl _apiRootUrl;
	};
}

#endif // LASTFMREQUESTBUILDER_HPP

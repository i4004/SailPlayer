#ifndef LASTFMREQUESTBUILDER_HPP
#define LASTFMREQUESTBUILDER_HPP

#include <QString>
#include <QNetworkRequest>

namespace Net
{
	class LastFmRequestBuilder
	{
	public:
		LastFmRequestBuilder();

		QNetworkRequest Build();

		static SetApplicationName(QString name) { ApplicationName = name; }
		static SetApplicationVersion(QString version) { ApplicationVersion = version; }
		static SetContactUrl(QString url) { ContactUrl = url; }

	private:
		QUrl _apiRootUrl;

		static QString ApplicationName;
		static QString ApplicationVersion;
		static QString ContactUrl;
	};
}

#endif // LASTFMREQUESTBUILDER_HPP

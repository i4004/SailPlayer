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

		static void SetApplicationName(QString name) { ApplicationName = name; }
		static void SetApplicationVersion(QString version) { ApplicationVersion = version; }
		static void SetContactUrl(QString url) { ContactUrl = url; }

	private:
		QUrl _apiRootUrl;

		static QString ApplicationName;
		static QString ApplicationVersion;
		static QString ContactUrl;
	};
}

#endif // LASTFMREQUESTBUILDER_HPP

#ifndef LASTFMQUERYBUILDER_HPP
#define LASTFMQUERYBUILDER_HPP

#include <QUrlQuery>
#include <QMap>

namespace Net
{
	class LastFmQueryBuilder
	{
	public:
		LastFmQueryBuilder();

		QUrlQuery Build(QString method, QMap<QString, QString> queryVariables);

		static QString GetApiKey() { return ApiKey; }
		static void SetApiKey(QString key) { ApiKey = key; }

		static QString GetSecret() { return Secret; }
		static void SetSecret(QString secret) { Secret = secret; }

	private:
		static QString ApiKey;
		static QString Secret;
	};
}

#endif // LASTFMQUERYBUILDER_HPP

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

		QUrlQuery Build(QString method, QString apiKey, QString secret, QMap<QString, QString> queryVariables);
	};
}

#endif // LASTFMQUERYBUILDER_HPP

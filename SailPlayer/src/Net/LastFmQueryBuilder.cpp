#include <QCryptographicHash>

#include "LastFmQueryBuilder.hpp"

namespace Net
{
	QString LastFmQueryBuilder::ApiKey = "";
	QString LastFmQueryBuilder::Secret = "";

	LastFmQueryBuilder::LastFmQueryBuilder()
	{
	}

	QUrlQuery LastFmQueryBuilder::Build(QString method, QMap<QString, QString> queryVariables)
	{
		QUrlQuery query;
		QString signatureInput = "";
		QByteArray signatureInputRaw;
		QMap<QString, QString>::iterator i;

		queryVariables.insert("method", method);
		queryVariables.insert("api_key", ApiKey);

		for (i = queryVariables.begin(); i != queryVariables.end(); ++i)
		{
			query.addQueryItem(i.key(), i.value());
			signatureInput += i.key() + i.value();
		}

		signatureInputRaw.append(signatureInput + Secret);

		query.addQueryItem("api_sig", QCryptographicHash::hash(signatureInputRaw, QCryptographicHash::Md5).toHex());

		return query;
	}
}

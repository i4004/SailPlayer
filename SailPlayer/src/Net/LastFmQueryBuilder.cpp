#include <QCryptographicHash>

#include "LastFmQueryBuilder.hpp"

namespace Net
{
	LastFmQueryBuilder::LastFmQueryBuilder()
	{
	}

	QUrlQuery LastFmQueryBuilder::Build(QString method, QString apiKey, QString secret, QMap<QString, QString> queryVariables)
	{
		QUrlQuery query;
		QString signatureInput = "";
		QByteArray signatureInputRaw;
		QMap<QString, QString>::iterator i;

		queryVariables.insert("method", method);
		queryVariables.insert("api_key", apiKey);

		for (i = queryVariables.begin(); i != queryVariables.end(); ++i)
		{
			query.addQueryItem(i.key(), i.value());
			signatureInput += i.key() + i.value();
		}

		signatureInputRaw.append(signatureInput + secret);

		query.addQueryItem("api_sig", QCryptographicHash::hash(signatureInputRaw, QCryptographicHash::Md5).toHex());

		return query;
	}
}

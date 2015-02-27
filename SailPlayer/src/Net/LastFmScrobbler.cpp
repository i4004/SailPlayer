#include <QUrlQuery>
#include <QCryptographicHash>

#include "LastFmScrobbler.hpp"

namespace Net
{
	LastFmScrobbler::LastFmScrobbler()
	{
	}

	QUrlQuery LastFmScrobbler::MakeRequest(QMap<QString, QString> variables)
	{
		QUrlQuery query;
		QByteArray signatureInputRaw;
		QString signatureInput = "";
		QMap<QString, QString>::iterator i;

		for (i = variables.begin(); i != variables.end(); ++i)
		{
			query.addQueryItem(i.key(), i.value());
			signatureInput += i.key() + i.value();
		}

		query.addQueryItem("api_key", _apiKey);

		signatureInputRaw.append(signatureInput + _secret);

		query.addQueryItem("api_sig", QCryptographicHash::hash(signatureInputRaw, QCryptographicHash::Md5).toHex());

		return query;
	}

	void LastFmScrobbler::Authenticate(QString userName, QString password)
	{
	}
}

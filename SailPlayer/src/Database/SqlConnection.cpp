#include "SqlConnection.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Database
{
	SqlConnection::SqlConnection()
	{
	}

	SqlConnection::~SqlConnection()
	{
	}

	bool SqlConnection::ExecuteQuery(QString query)
	{
		#ifdef QT_DEBUG
		qDebug() << "Executing query:" << query;
		#endif

		QSqlQuery q(_db);

		bool result = q.exec(query);

		if(!result)
			_lastError = q.lastError();

		_lastQuery = q;

		return result;
	}
}

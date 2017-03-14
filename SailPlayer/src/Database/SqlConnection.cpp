#include <QSqlQuery>

#include "SqlConnection.hpp"

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
		QSqlQuery q(_db);
//		QSqlQuery q2 = new QSqlQuery(_db);

		bool result = q.exec(query);

		if(!result)
			_lastError = q.lastError();

		return result;
	}

	QSqlError SqlConnection::GetLastError()
	{
		return _lastError;
	}
}

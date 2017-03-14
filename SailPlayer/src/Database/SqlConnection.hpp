#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

namespace Database
{
	class SqlConnection
	{
	public:
		SqlConnection();
		virtual ~SqlConnection();

		virtual bool ExecuteQuery(QString query);

		virtual QSqlQuery GetLastQuery() { return _lastQuery; }
		virtual QSqlError GetLastError() { return _lastError; }

	protected:
		QSqlDatabase _db;

		QSqlQuery _lastQuery;
		QSqlError _lastError;
	};
}

#endif // SQLCONNECTION_H

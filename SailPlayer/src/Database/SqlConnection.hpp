#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>

namespace Database
{
	class SqlConnection
	{
	public:
		SqlConnection();
		virtual ~SqlConnection();

		virtual bool ExecuteQuery(QString query);

		virtual QSqlError GetLastError();

	protected:
		QSqlDatabase _db;

		QSqlError _lastError;
	};
}

#endif // SQLCONNECTION_H

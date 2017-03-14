#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QSqlDatabase>

namespace Database
{
	class SqlConnection
	{
	public:
		SqlConnection();
		virtual ~SqlConnection();

		virtual bool ExecuteQuery(QString query);

	protected:
		QSqlDatabase _db;
	};
}

#endif // SQLCONNECTION_H

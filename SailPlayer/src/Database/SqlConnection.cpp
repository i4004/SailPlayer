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

		return q.exec(query);
	}
}

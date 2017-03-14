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

		bool result = q.exec(query);

		if(!result)
			_lastError = q.lastError();

		_lastQuery = q;

		return result;
	}
}

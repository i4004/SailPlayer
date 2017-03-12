#include "SQLiteConnection.hpp"

namespace Database
{
	SQLiteConnection::SQLiteConnection(QString databaseName)
	{
		_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
	}

	SQLiteConnection::~SQLiteConnection()
	{
		delete _db;
	}
}

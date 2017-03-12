#ifndef SQLITECONNECTION_H
#define SQLITECONNECTION_H

#include <QString>
#include <QSqlDatabase>

namespace Database
{
	class SQLiteConnection
	{
	public:
		SQLiteConnection(QString databaseName);
		~SQLiteConnection();

	private:
		QSqlDatabase* _db;
	};
}

#endif // SQLITECONNECTION_H

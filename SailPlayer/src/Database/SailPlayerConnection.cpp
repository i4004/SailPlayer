#include <QSqlError>

#include "SailPlayerConnection.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Database
{
	SailPlayerConnection::SailPlayerConnection(QString databaseFilePath)
	{	
		_db = QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));

		_db.setDatabaseName(databaseFilePath);

		#ifdef QT_DEBUG
		qDebug() << "Opening database:" << databaseFilePath;
		#endif

		if(!_db.open())
			qFatal("Database open failed: %s", _db.lastError().text().toUtf8().constData());
	}

	SailPlayerConnection::~SailPlayerConnection()
	{
		if(_db.isOpen())
		{
			#ifdef QT_DEBUG
			qDebug() << "Closing database";
			#endif

			_db.close();
		}
	}
}

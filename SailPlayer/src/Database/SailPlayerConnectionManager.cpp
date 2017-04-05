#include <QDir>
#include <QStandardPaths>\

#include "SailPlayerConnectionManager.hpp"

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Database
{
	QString SailPlayerConnectionManager::DatabaseName = "SailPlayer.sqlite";

	SailPlayerConnectionManager::SailPlayerConnectionManager()
	{
		QString dataLocation = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
		QString databaseFilePath = dataLocation + "/" + DatabaseName;

		CreateDatabasePathIfNotExist(dataLocation);

		_connection = new SailPlayerConnection(databaseFilePath);

		ExportDatabaseSchemaIfNotExist();
	}

	SailPlayerConnectionManager::~SailPlayerConnectionManager()
	{
		delete _connection;
	}

	void SailPlayerConnectionManager::CreateDatabasePathIfNotExist(QString dataLocation)
	{
		QDir location(dataLocation);

		if (!location.exists())
		{
			#ifdef QT_DEBUG
			qDebug() << "Creating data location:" << dataLocation;
			#endif

			if (!location.mkpath(location.absolutePath()))
				qFatal("Unable to make path: %s", dataLocation.toUtf8().constData());
		}
	}

	void SailPlayerConnectionManager::ExportDatabaseSchemaIfNotExist()
	{
		static QStringList queries = QStringList() <<
			"PRAGMA foreign_keys = ON;" <<

			"CREATE TABLE IF NOT EXISTS Playlists(ID INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT);" <<

			"CREATE TABLE IF NOT EXISTS Tracks"
			"("
			"ID INTEGER PRIMARY KEY AUTOINCREMENT,"
			"PlaylistID INTEGER,"\
			"ArtistName TEXT,"
			"AlbumName TEXT,"
			"AlbumYear INTEGER,"
			"Number INTEGER,"
			"Name TEXT,"
			"StartPosition INTEGER,"
			"EndPosition INTEGER,"
			"FileName TEXT,"
			"FullFilePath TEXT,"
			"FOREIGN KEY(PlaylistID) REFERENCES Playlists(ID)"
			");";

		foreach (QString query, queries)
		{
			if (!_connection->ExecuteQuery(query))
				qFatal("Unable to execute database schema export query: '%s'", QString(query + ", error: '" + _connection->GetLastError().text() + "'").toUtf8().constData());
		}
	}
}

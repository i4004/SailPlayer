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
	}
}

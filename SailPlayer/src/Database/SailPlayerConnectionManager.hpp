#ifndef SAILPLAYERCONNECTIONMANAGER_H
#define SAILPLAYERCONNECTIONMANAGER_H

#include "SailPlayerConnection.hpp"

namespace Database
{
	class SailPlayerConnectionManager
	{
	public:
		SailPlayerConnectionManager();
		~SailPlayerConnectionManager();

		SailPlayerConnection* GetConnection() const { return _connection; }

	private:
		static QString DatabaseName;

		SailPlayerConnection* _connection;

		void CreateDatabasePathIfNotExist(QString dataLocation);
		void ExportDatabaseSchemaIfNotExist();
	};
}

#endif // SAILPLAYERCONNECTIONMANAGER_H

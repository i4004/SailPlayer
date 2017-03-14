#ifndef SAILPLAYERCONNECTION_H
#define SAILPLAYERCONNECTION_H

#include <QString>

#include "SqlConnection.hpp"

namespace Database
{
	class SailPlayerConnection : SqlConnection
	{
	public:
		SailPlayerConnection(QString databaseFilePath);
		~SailPlayerConnection();
	};
}

#endif // SAILPLAYERCONNECTION_H

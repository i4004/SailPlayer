#include <QSqlQuery>
#include <QVariant>

#include "PlaylistsRepository.hpp"

namespace Database
{
	namespace Repositories
	{
		QString PlaylistsRepository::TableName = "Playlists";

		PlaylistsRepository::PlaylistsRepository(SqlConnection* connection)
			: _connection(connection)
		{
		}

		int PlaylistsRepository::AddItem(QString name)
		{
			if(_connection->ExecuteQuery(QString("INSERT INTO %1 VALUES(NULL,'%2')")
			.arg(TableName).arg(name)))
				return _connection->GetLastQuery().lastInsertId().toInt();
			else
				return -1;
		}

		QList<Playlist*> PlaylistsRepository::GetItems()
		{
			QList<Playlist*> items;

			return items;
		}
	}
}



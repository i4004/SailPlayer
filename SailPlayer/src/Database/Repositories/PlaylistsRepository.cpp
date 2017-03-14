#include <QSqlQuery>

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

		void PlaylistsRepository::AddItem(QString name)
		{
//			_connection->ExecuteQuery(QString("INSERT INTO %1 VALUES(NULL,'%2')")
//			.arg(TableName).arg(name));
		}

		QList<Playlist*> PlaylistsRepository::GetItems()
		{
			QList<Playlist*> items;

			return items;
		}
	}
}



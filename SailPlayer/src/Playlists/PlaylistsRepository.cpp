#include <QSqlQuery>
#include <QVariant>

#include "PlaylistsRepository.hpp"

namespace Playlists
{
	QString PlaylistsRepository::TableName = "Playlists";

	PlaylistsRepository::PlaylistsRepository(SqlConnection* connection, PlaylistFactory* factory)
		: _connection(connection), _factory(factory)
	{
	}

	int PlaylistsRepository::AddItem(QString name)
	{
		if(_connection->ExecuteQuery(QString("INSERT INTO %1 VALUES(NULL,'%2')").arg(TableName).arg(name)))
			return _connection->GetLastQuery().lastInsertId().toInt();
		else
			return -1;
	}

	QList<Playlist*> PlaylistsRepository::GetItems()
	{
		QList<Playlist*> items;

		_connection->ExecuteQuery(QString("SELECT * FROM %1").arg(TableName));

		QSqlQuery query = _connection->GetLastQuery();

		while(query.next())
		{
			int id = query.value(0).toInt();
			QString name = query.value(1).toString();

			items.append(_factory->Create(id, name));
		}

		return items;
	}
}



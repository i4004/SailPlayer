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

	int PlaylistsRepository::AddItem(Playlist* item)
	{
		if(_connection->ExecuteQuery(QString("INSERT INTO %1 VALUES(NULL,'%2')").arg(TableName).arg(item->GetName())))
		{
			int id = _connection->GetLastQuery().lastInsertId().toInt();

			item->SetID(id);

			return id;
		}
		else
			return -1;
	}

	Playlist* PlaylistsRepository::GetItem(int id)
	{
		if(!_connection->ExecuteQuery(QString("SELECT * FROM %1 WHERE ID = %2").arg(TableName).arg(id)))
			return nullptr;

		QSqlQuery query = _connection->GetLastQuery();

		if(!query.first())
			return nullptr;

		QString name = query.value(1).toString();

		return _factory->Create(id, name);
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

	bool PlaylistsRepository::UpdateItem(Playlist* item)
	{
		return _connection->ExecuteQuery(QString("UPDATE %1 SET Name = '%3' WHERE ID = %2").arg(TableName).arg(item->GetID()).arg(item->GetName()));
	}

	bool PlaylistsRepository::DeleteItem(Playlist* item)
	{
		return _connection->ExecuteQuery(QString("DELETE FROM %1 WHERE ID = %2").arg(TableName).arg(item->GetID()));
	}
}



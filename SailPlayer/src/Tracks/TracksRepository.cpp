#include <QSqlQuery>
#include <QVariant>

#include "TracksRepository.hpp"

namespace Tracks
{
	QString TracksRepository::TableName = "Tracks";

	TracksRepository::TracksRepository(SqlConnection* connection, TrackFactory* factory)
		: _connection(connection), _factory(factory)
	{
	}

	int TracksRepository::AddItem(Track* item)
	{
		if(_connection->ExecuteQuery(QString("INSERT INTO %1 VALUES(NULL,'%2','%3','%4','%5','%6','%7','%8','%9','%10','%11')").arg(TableName)
									 .arg(item->GetPlaylistID())
									 .arg(item->GetArtistName())
									 .arg(item->GetAlbumName())
									 .arg(item->GetAlbumYear())
									 .arg(item->GetNumber())
									 .arg(item->GetName())
									 .arg(item->GetStartPosition())
									 .arg(item->GetEndPosition())
									 .arg(item->GetFileName())
									 .arg(item->GetFullFilePath())))
		{
			int id = _connection->GetLastQuery().lastInsertId().toInt();

			item->SetID(id);

			return id;
		}
		else
			return -1;
	}

	QList<Track*> TracksRepository::GetItems(int playlistID)
	{
		QList<Track*> items;

		_connection->ExecuteQuery(QString("SELECT * FROM %1 WHERE PlaylistID = %2").arg(TableName).arg(playlistID));

		QSqlQuery query = _connection->GetLastQuery();

		while(query.next())
		{
			items.append(_factory->Create(query.value(0).toInt(),
										  query.value(1).toInt(),
										  query.value(2).toString(),
										  query.value(3).toString(),
										  query.value(4).toInt(),
										  query.value(5).toInt(),
										  query.value(6).toString(),
										  query.value(7).toInt(),
										  query.value(8).toInt(),
										  query.value(9).toString(),
										  query.value(10).toString()));
		}

		return items;
	}

	bool TracksRepository::DeleteItems(int playlistID)
	{
		return _connection->ExecuteQuery(QString("DELETE FROM %1 WHERE PlaylistID = %2").arg(TableName).arg(playlistID));
	}
}



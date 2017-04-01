#ifndef PLAYLISTSREPOSITORY_H
#define PLAYLISTSREPOSITORY_H

#include <QList>

#include "../Database/SqlConnection.hpp"
#include "Playlist.hpp"
#include "PlaylistFactory.hpp"

using namespace Database;

namespace Playlists
{
	class PlaylistsRepository
	{
	public:
		PlaylistsRepository(SqlConnection* connection, PlaylistFactory* factory);

		int AddItem(QString name);

		Playlist* GetItem(int id);
		QList<Playlist*> GetItems();

		bool UpdateItem(int id, QString name);

		bool DeleteItem(int id);

	private:
		static QString TableName;

		SqlConnection* _connection;
		PlaylistFactory* _factory;
	};
}

#endif // PLAYLISTSREPOSITORY_H

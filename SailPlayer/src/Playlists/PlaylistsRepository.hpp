#ifndef PLAYLISTSREPOSITORY_H
#define PLAYLISTSREPOSITORY_H

#include <QList>

#include "../Database/SqlConnection.hpp"
#include "Playlist.hpp"

using namespace Database;

namespace Playlists
{
	class PlaylistsRepository
	{
	public:
		PlaylistsRepository(SqlConnection* connection);

		int AddItem(QString name);

		QList<Playlist*> GetItems();

	private:
		static QString TableName;

		SqlConnection* _connection;
	};
}

#endif // PLAYLISTSREPOSITORY_H

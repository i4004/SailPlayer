#ifndef PLAYLISTSREPOSITORY_H
#define PLAYLISTSREPOSITORY_H

#include <QList>

#include "../SqlConnection.hpp"
#include "../../Tracks/Playlist.hpp"

using namespace Tracks;

namespace Database
{
	namespace Repositories
	{
		class PlaylistsRepository
		{
		public:
			PlaylistsRepository(SqlConnection* connection);

			void AddItem(QString name);

			QList<Playlist*> GetItems();

		private:
			static QString TableName;

			SqlConnection* _connection;
		};
	}
}

#endif // PLAYLISTSREPOSITORY_H

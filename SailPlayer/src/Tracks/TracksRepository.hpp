#ifndef PLAYLISTSREPOSITORY_H
#define PLAYLISTSREPOSITORY_H

#include <QList>

#include "../Database/SqlConnection.hpp"
#include "Track.hpp"
#include "TrackFactory.hpp"

using namespace Database;

namespace Tracks
{
	class TracksRepository
	{
	public:
		TracksRepository(SqlConnection* connection, TrackFactory* factory);

		int AddItem(Track* track);

		Track* GetItem(int id);
		QList<Track*> GetItems(int playlistID);

		bool DeleteItems(int playlistID);

	private:
		static QString TableName;

		SqlConnection* _connection;
		TrackFactory* _factory;
	};
}

#endif // PLAYLISTSREPOSITORY_H

#include "PlaylistFactory.hpp"

namespace Playlists
{
	Playlist* PlaylistFactory::Create(QString name)
	{
		Playlist* item = new Playlist();

		item->SetName(name);

		return item;
	}

	Playlist* PlaylistFactory::Create(int id, QString name)
	{
		Playlist* item = Create(name);

		item->SetID(id);

		return item;
	}
}

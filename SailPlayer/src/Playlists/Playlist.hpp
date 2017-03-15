#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>

namespace Playlists
{
	class Playlist
	{
	public:
		Playlist(int id, QString name);

		inline int GetID() { return _id; }
		inline QString GetName() { return _name; }

	private:
		int _id;
		QString _name;
	};
}

#endif // PLAYLIST_H

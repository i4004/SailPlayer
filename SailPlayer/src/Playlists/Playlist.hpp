#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>

namespace Playlists
{
	class Playlist
	{
	public:
		Playlist(QString name);

		inline QString GetName() { return _name; }

	private:
		QString _name;
	};
}

#endif // PLAYLIST_H

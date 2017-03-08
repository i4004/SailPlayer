#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QString>

namespace Tracks
{
	class Playlist
	{
	public:
		Playlist();

		inline QString GetName() { return _name; }

	private:
		QString _name;
	};
}

#endif // PLAYLIST_H

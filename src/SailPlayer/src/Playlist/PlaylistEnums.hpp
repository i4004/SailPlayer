#ifndef PLAYLISTENUMS_HPP
#define PLAYLISTENUMS_HPP

#include <QObject>

namespace Playlist
{
	class PlaylistEnums : public QObject
	{
		Q_OBJECT
		Q_ENUMS(PlayDirection)
		Q_ENUMS(PlayOrder)

	public:
		enum PlayDirection
		{
			ByIndex = 0,
			Next = 1,
			// Ignoring repeat single track order
			NextWithForce = 2,
			Previous = 3
		};

		enum PlayOrder
		{
			Default = 0,
			RepeatPlaylist = 1,
			RepeatTrack = 2,
			Random = 3
		};
	};
}

#endif // PLAYLISTENUMS_HPP

#ifndef SAILPLAYER_HPP
#define SAILPLAYER_HPP

#include <QObject>

class SailPlayer : public QObject
{
public:
	Q_OBJECT
	Q_ENUMS(PlayDirection)
	Q_ENUMS(PlayOrder)

public:
	enum PlayDirection
	{
		ByIndex = 0,
		Next = 1,
		// Ignoring repeat track order
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

#endif // SAILPLAYER_HPP

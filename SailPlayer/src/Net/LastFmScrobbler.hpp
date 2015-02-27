#ifndef LASTFMSCROBBLER_HPP
#define LASTFMSCROBBLER_HPP

#include <QObject>

namespace Net
{
	class LastFmScrobbler  : public QObject
	{
		Q_OBJECT

	public:
		LastFmScrobbler();
	};
}

#endif // LASTFMSCROBBLER_HPP

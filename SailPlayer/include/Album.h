#include "Track.h"

class Album
{
private:
	QList<Track> tracks;

public:
	Album(QList<Track> tracks);

	QList<Track> GetTracks();
};

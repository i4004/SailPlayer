#include <QList>
#include "Album.h"

Album::Album(QList<Track> tracks)
{
	this->tracks = tracks;
}

QList<Track> Album::GetTracks()
{
	return tracks;
}

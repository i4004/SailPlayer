#include <QList>

#include "Album.h"

namespace Entities
{
	Album::Album(const QList<Track>& tracks) : _tracks(tracks)
	{
	}
}

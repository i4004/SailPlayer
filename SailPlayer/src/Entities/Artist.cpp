#include <QList>

#include "Artist.h"

namespace Entities
{
	Artist::Artist(const QList<Album>& albums) : _albums(albums)
	{
	}
}

#include <QList>
#include "Artist.h"

Artist::Artist(QList<Album> albums)
{
	this->albums = albums;
}

QList<Album> Artist::GetAlbums()
{
	return albums;
}

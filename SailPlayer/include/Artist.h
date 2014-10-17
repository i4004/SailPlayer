#include "Album.h"

class Artist
{
private:
	QList<Album> albums;

public:
	Artist(QList<Album> albums);

	QList<Album> GetAlbums();
};

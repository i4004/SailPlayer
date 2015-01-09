#include "Album.h"

namespace Entities
{
	class Artist
	{
	public:
		Artist(const QList<Album>& albums);

		QList<Album> GetAlbums() const { return _albums; }

	private:
		QList<Album> _albums;
	};
}

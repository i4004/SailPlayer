#include "Track.h"

namespace Entities
{
	class Album
	{
	public:
		Album(const QList<Track>& tracks);

		QList<Track> GetTracks() const { return _tracks; }

	private:
		QList<Track> _tracks;
	};
}

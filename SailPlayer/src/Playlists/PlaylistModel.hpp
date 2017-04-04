#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include "../Model/ListModel.hpp"
#include "../Tracks/Track.hpp"

using namespace Model;
using namespace Tracks;

namespace Playlists
{
	class PlaylistModel : public ListModel<Track>
	{
		Q_OBJECT

	public:
		PlaylistModel(QObject* parent = nullptr);

		QVariant GetItemData(int role, Track* item) const;

	private:
		static QChar SectionSeparator;
	};
}

#endif // PLAYLISTMODEL_H

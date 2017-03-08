#ifndef PLAYLISTSMODEL_H
#define PLAYLISTSMODEL_H

#include "ListModel.hpp"
#include "../Tracks/Playlist.hpp"

using namespace Tracks;

namespace Model
{
	enum PlaylistsModelRoles
	{
		NameRole = Qt::UserRole + 1
	};

	class PlaylistsModel : public ListModel<Playlist>
	{
		Q_OBJECT

	public:
		PlaylistsModel(QObject* parent = 0);

		QVariant GetItemData(int role, Playlist* item) const;
	};
}

#endif // PLAYLISTSMODEL_H

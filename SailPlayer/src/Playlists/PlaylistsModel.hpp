#ifndef PLAYLISTSMODEL_H
#define PLAYLISTSMODEL_H

#include "../Model/ListModel.hpp"
#include "../Playlists/Playlist.hpp"

using namespace Model;

namespace Playlists
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

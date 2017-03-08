#include "PlaylistsModel.hpp"

namespace Model
{
	PlaylistsModel::PlaylistsModel(QObject* parent) : ListModel<Playlist>(parent)
	{
		_rolesNames.insert(NameRole, QByteArray("playlistName"));
	}

	QVariant PlaylistsModel::GetItemData(int role, Playlist* item) const
	{
		switch (role)
		{
			case Qt::DisplayRole:

			case NameRole:
				return item->GetName();

			default:
				return QVariant();
		}
	}
}

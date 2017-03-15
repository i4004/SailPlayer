#include "PlaylistsModel.hpp"

namespace Playlists
{
	PlaylistsModel::PlaylistsModel(QObject* parent) : ListModel<Playlist>(parent)
	{
		_rolesNames.insert(IdRole, QByteArray("id"));
		_rolesNames.insert(NameRole, QByteArray("name"));
	}

	QVariant PlaylistsModel::GetItemData(int role, Playlist* item) const
	{
		switch (role)
		{
			case Qt::DisplayRole:

			case IdRole:
				return item->GetID();

			case NameRole:
				return item->GetName();

			default:
				return QVariant();
		}
	}

	bool PlaylistsModel::DeleteItemByID(int id)
	{
		foreach (Playlist* item, _items)
		{
			if (item->GetID() == id)
			{
				int index = _items.indexOf(item);

				beginRemoveRows(QModelIndex(), index, index);

				_items.removeAt(index);

				endRemoveRows();

				return true;
			}
		}

		return false;
	}
}

#include "PlaylistsModel.hpp"

namespace Playlists
{
	PlaylistsModel::PlaylistsModel(QObject* parent) : ListModel<Playlist>(parent)
	{
		_rolesNames.insert(NameRole, QByteArray("name"));

		QList<Playlist*> list;

		list.append(new Playlist("Test 1"));
		list.append(new Playlist("Dream Theater"));
		list.append(new Playlist("Circus Maximus"));

		AddItems(list);
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

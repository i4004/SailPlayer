#include "PlaylistsModel.hpp"

#include <QQmlEngine>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace Playlists
{
	enum PlaylistsModelRoles
	{
		IdRole = Qt::UserRole + 1,
		NameRole = Qt::UserRole + 2
	};

	PlaylistsModel::PlaylistsModel(QObject* parent) : ListModel<Playlist>(parent)
	{
		QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

		#ifdef QT_DEBUG
		qDebug() << "Construction";
		#endif

		AddRole(IdRole, QByteArray("id"));
		AddRole(NameRole, QByteArray("name"));
	}

	PlaylistsModel::~PlaylistsModel()
	{
		#ifdef QT_DEBUG
		qDebug() << "Destruction";
		#endif
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

	Playlist* PlaylistsModel::GetItem(int id)
	{
		foreach (Playlist* item, GetItems())
		{
			if (item->GetID() == id)
				return item;
		}

		return nullptr;
	}
}

#include "PlaylistModel.h"

namespace Models
{
	enum PlaylistModelRoles
	{
		ArtistNameRole = Qt::UserRole + 1,
		AlbumNameRole = Qt::UserRole + 2,
		AlbumModelRole = Qt::UserRole + 3
	};

	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_tracksLoader = new TracksLoader(_tracksFactory, _filesFactory);
		_albumModelsFactory = new AlbumModelsFactory(*_tracksLoader);

		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(ArtistNameRole, QByteArray("artistName"));
		_rolesNames.insert(AlbumNameRole, QByteArray("albumName"));
		_rolesNames.insert(AlbumModelRole, QByteArray("albumModel"));
	}

	PlaylistModel::~PlaylistModel()
	{
		Cleanup();

		delete _albumModelsFactory;
		delete _tracksLoader;
	}

	void PlaylistModel::Cleanup()
	{
		while (!_albumsList.isEmpty())
			 delete _albumsList.takeFirst();
	}

	int PlaylistModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _albumsList.count();
	}

	QVariant PlaylistModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() > _albumsList.size() - 1)
			return QVariant();

		AlbumModel* item = _albumsList.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case ArtistNameRole:
				return item->GetArtistName();

			case AlbumNameRole:
				return item->GetAlbumName();

//			case AlbumModelRole:
//				return (QObject)*item;
//				return QVariant::fromValue((QObject)*item);

			default:
				return QVariant();
		}
	}

	AlbumModel* PlaylistModel::getAlbumModel(int index)
	{
		return _albumsList.at(index);
	}

	void PlaylistModel::addTracks(QString directoryPath)
	{
		_filesFactory.SetDirectoryPath(directoryPath);
		QList<AlbumModel*> albums = _albumModelsFactory->Build();

		beginResetModel();

		_albumsList.append(albums);

		endResetModel();
	}
}

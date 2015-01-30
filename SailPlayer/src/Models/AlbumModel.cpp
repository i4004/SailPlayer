#include "AlbumModel.h"

namespace Models
{
	enum AlbumModelRoles
	{
		TrackNumberRole = Qt::UserRole + 1,
		TrackNameRole = Qt::UserRole + 2,
		TrackDurationRole = Qt::UserRole + 3
	};

	AlbumModel::AlbumModel(QObject* parent)
	{
		Q_UNUSED(parent);

		_rolesNames = QAbstractListModel::roleNames();
		_rolesNames.insert(TrackNumberRole, QByteArray("trackNumber"));
		_rolesNames.insert(TrackNameRole, QByteArray("trackName"));
		_rolesNames.insert(TrackDurationRole, QByteArray("trackDuration"));
	}

	AlbumModel::~AlbumModel()
	{
		Cleanup();
	}

	void AlbumModel::Cleanup()
	{
		while (!_tracksList.isEmpty())
			 delete _tracksList.takeFirst();
	}

	int AlbumModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _tracksList.count();
	}

	QVariant AlbumModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() > _tracksList.size() - 1)
			return QVariant();

		Track* item = _tracksList.at(index.row());

		switch (role)
		{
			case Qt::DisplayRole:

			case TrackNumberRole:
				return item->GetNumber();

			case TrackNameRole:
				return item->GetName();

			case TrackDurationRole:
				return item->GetDuration();

			default:
				return QVariant();
		}
	}

	QString  AlbumModel::GetArtistName()
	{
		return _tracksList.count() > 0 ? _tracksList.first()->GetArtistName() : "";
	}

	QString  AlbumModel::GetAlbumName()
	{
		return _tracksList.count() > 0 ? _tracksList.first()->GetAlbumName() : "";
	}

	int AlbumModel::GetAlbumYear()
	{
		return _tracksList.count() > 0 ? _tracksList.first()->GetAlbumYear() : 0;
	}
}
